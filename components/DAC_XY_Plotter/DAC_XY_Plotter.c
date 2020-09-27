#include "DAC_XY_Plotter.h"
#include "DAC_XY_Plotter_priv.h"

#include "I2SManager.h"

#include "GraphicItem.h"

#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "XYPlotter";
#include "esp_err.h"
#include "esp_log.h"

#define max(x,y) ((x)>(y) ? (x) : (y))

static int id_incr = 0;

void XYPlotter_init(int rate) {
	I2SManager_init(rate);

	xTaskCreatePinnedToCore(_XYPlotter_feeder, "XYPlotter-feeder", 2048, NULL, 10, NULL, 0);
}

void _XYPlotter_feeder() {
	size_t bytesWritten;
	while(1) {
		GraphicItem_t *p_item = cll_next_item();
		if(p_item != NULL) {
			I2SManager_write_8bitLR(p_item->points.bytes, p_item->sizeof_points, &bytesWritten, portMAX_DELAY);
		} else {
			vTaskDelay(1);
		}
    }
    vTaskDelete(NULL);
}

void XYPlotter_drawPoint(int x, int y, Pen_t pen) {
	GraphicItem_t *p_item = GI_create();

	p_item->sizeof_points = pen.intensity * sizeof(Coord_t);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	for(int i=0;i<pen.intensity;i++) {
		p_item->points.coord[i] = (Coord_t) {.x = x, .y = y};
	}
}

void XYPlotter_drawLine(int x1, int y1, int x2, int y2, Pen_t pen) {
	GraphicItem_t *p_item = GI_create();

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/pen.spacing);
	const int subPointsNb = macroPointsNb * pen.intensity;
	
	p_item->sizeof_points = subPointsNb * sizeof(Coord_t);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	Coord_t runningPoint;
	for(int n=0;n<macroPointsNb;n++) {
		runningPoint.x = x1 + n * (x2 - x1) / max(macroPointsNb-1, 1);
		runningPoint.y = y1 + n * (y2 - y1) / max(macroPointsNb-1, 1);
		for(int i=0;i<pen.intensity;i++) {
			p_item->points.coord[n * pen.intensity + i ] = runningPoint;
		}
	}
}