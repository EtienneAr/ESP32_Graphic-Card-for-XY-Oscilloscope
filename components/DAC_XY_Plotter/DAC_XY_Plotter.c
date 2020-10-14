#include "DAC_XY_Plotter.h"
#include "DAC_XY_Plotter_priv.h"

#include "I2SManager.h"

#include "GraphicItem.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "XYPlotter";
#include "esp_err.h"
#include "esp_log.h"

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
				I2SManager_write_8bitLR(p_item->points.bytes, p_item->sizeof_points, &bytesWritten, portMAX_DELAY);
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

void XYPlotter_move(GI_uid_t uid, int dx, int dy) {
	GraphicItem_t *p_item = uid;

	GI_wait_take(p_item);
	for(int i=0;i<p_item->sizeof_points/sizeof(Coord_t);i++) {
		p_item->points.coord[i].x += dx;
		p_item->points.coord[i].y += dy;
	}
	GI_giveBack(p_item);
}

void XYPlotter_setVisibility(GI_uid_t uid, bool isVisible) {
	GraphicItem_t *p_item = uid;

	GI_wait_take(p_item);
	p_item->isVisible = isVisible;
	GI_giveBack(p_item);
}

void XYPlotter_clearScreen() {
	GI_delete_all();
}

GI_uid_t XYPlotter_drawPoint(float x, float y, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawPoint(NULL, x, y, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawPoint(p_item->points.bytes, x, y, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}

GI_uid_t XYPlotter_drawLine(float x1, float y1, float x2, float y2, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawLine(NULL, x1, y1, x2, y2, pen.spacing, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawLine(p_item->points.bytes, x2, y2, x1, y1, pen.spacing, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}


GI_uid_t XYPlotter_drawRect(float x1, float y1, float x2, float y2, Pen_t pen){
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawRect(NULL, x1, y1, x2, y2, pen.spacing, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawRect(p_item->points.bytes, x1, y1, x2, y2, pen.spacing, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}


GI_uid_t XYPlotter_drawArc(float x, float y, float r, float a1, float a2, Pen_t pen){
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawArc(NULL, x, y, r, a1, a2, pen.spacing, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawArc(p_item->points.bytes, x, y, r, a1, a2, pen.spacing, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}


GI_uid_t XYPlotter_drawChar(char c, float x, float y, float height, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawChar(NULL, c, x, y, height, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawChar(p_item->points.bytes, c, x, y, height, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}

GI_uid_t XYPlotter_drawString(const char* str, float x, float y, float height, Pen_t pen) {
	GraphicItem_t *p_item = GI_create_take();

	p_item->sizeof_points = GO_drawString(NULL, str, x, y, height, pen.intensity);
	p_item->points.bytes = malloc(p_item->sizeof_points);

	GO_drawString(p_item->points.bytes, str, x, y, height, pen.intensity);

	GI_giveBack(p_item);
	return (GI_uid_t) p_item;
}