#include "DAC_XY_Plotter.h"
#include "DAC_XY_Plotter_priv.h"

#include "I2SManager.h"
#include "CircularLinkedList.h"
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

	Pen_t myPen = { .spacing = 1, .intensity = 10 };
	XYPlotter_drawLine(0,0, 255,255, myPen);

	xTaskCreatePinnedToCore(_XYPlotter_feeder, "XYPlotter-feeder", 2048, NULL, 10, NULL, 0);
}

void _XYPlotter_feeder() {
	size_t bytesWritten;
	while(1) {
		GraphicItem_t *p_item = cll_next_item();
		if(p_item != NULL) {
			I2SManager_write_8bitLR(p_item->points, p_item->sizeof_points, &bytesWritten, portMAX_DELAY);
		} else {
			I2SManager_write_blank();
		}
		vTaskDelay(100 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

GraphicItem_t *_XYPlotter_create_new_item() {
	GraphicItem_t *p_item = malloc(sizeof(GraphicItem_t));
	p_item->id = id_incr++;
	p_item->isVisible = true;
	return p_item;
}

void XYPlotter_drawPoint(int x, int y, Pen_t pen) {
	GraphicItem_t *p_item = _XYPlotter_create_new_item();

	p_item->sizeof_points = pen.intensity * 2 * sizeof(uint8_t);
	p_item->points = malloc(p_item->sizeof_points);

	for(int i=0;i<p_item->sizeof_points;i+=2) {
		p_item->points[i] = x;
		p_item->points[i+1] = y;
	}

	cll_add_item(p_item);
}

void XYPlotter_drawLine(int x1, int y1, int x2, int y2, Pen_t pen) {
	GraphicItem_t *p_item = _XYPlotter_create_new_item();

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/pen.spacing);
	const int subPointsNb = macroPointsNb * pen.intensity;
	
	p_item->sizeof_points = subPointsNb * 2 * sizeof(uint8_t);
	p_item->points = malloc(p_item->sizeof_points);

	int x, y;
	for(int n=0;n<macroPointsNb;n++) {
		x = x1 + n * (x2 - x1) / max(macroPointsNb-1, 1);
		y = y1 + n * (y2 - y1) / max(macroPointsNb-1, 1);
		for(int i=0;i<pen.intensity;i++) {
			p_item->points[2 * n * pen.intensity + 2*i    ] = x;
			p_item->points[2 * n * pen.intensity + 2*i + 1] = y;	
		}
	}

	cll_add_item(p_item);
}