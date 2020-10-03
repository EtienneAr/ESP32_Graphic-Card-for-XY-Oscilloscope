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

void XYPlotter_init(int rate) {
	I2SManager_init(rate);
	GI_initMutex();

	xTaskCreatePinnedToCore(_XYPlotter_feeder, "XY-feeder", 2048, NULL, 10, NULL, 1);
}

void _XYPlotter_feeder() {
	size_t bytesWritten;
	while(1) {
		GraphicItem_t *p_item = GI_get_next_take();
		if(p_item != NULL) {
			if(p_item->isVisible && p_item->sizeof_points > 0) {
				I2SManager_write_16bitLR(p_item->points.bytes, p_item->sizeof_points, &bytesWritten, portMAX_DELAY);
			}
			GI_giveBack(p_item);
		} else {
			vTaskDelay(1);
		}
    }
    vTaskDelete(NULL);
}

void XYPlotter_delete(GI_uid_t uid) {
	GraphicItem_t *p_item = (GraphicItem_t*) uid;
	
	GI_delete(p_item);
}

GI_uid_t XYPlotter_drawPoint(int x, int y, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = pen.intensity * sizeof(Coord_t);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	for(int i=0;i<pen.intensity;i++) {
		p_item->points.coord[i] = (Coord_t) {.x = x, .y = y};
	}

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}

GI_uid_t XYPlotter_drawLine(int x1, int y1, int x2, int y2, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/pen.spacing);
	const int subPointsNb = macroPointsNb * pen.intensity;
	
	p_item->sizeof_points = subPointsNb * sizeof(Coord_t);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	Coord_t runningPoint;
	for(int n=0;n<macroPointsNb;n++) {
		runningPoint.x = x2 + n * (x1 - x2) / max(macroPointsNb-1, 1);
		runningPoint.y = y2 + n * (y1 - y2) / max(macroPointsNb-1, 1);
		for(int i=0;i<pen.intensity;i++) {
			p_item->points.coord[n * pen.intensity + i ] = runningPoint;
		}
	}

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}