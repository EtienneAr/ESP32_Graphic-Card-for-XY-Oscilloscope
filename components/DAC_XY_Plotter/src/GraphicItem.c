#include "GraphicItem.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

SemaphoreHandle_t mutex;


void GI_delete(GraphicItem_t* p_item) {
	if(p_item != NULL) {
		if(p_item->points.bytes != NULL) {
			free(p_item->points.bytes);
		}

		free(p_item);	
	}
}

GraphicItem_t* GI_create() {
	GraphicItem_t *p_item = malloc(sizeof(GraphicItem_t));
	p_item->isAvailable = false;
	p_item->isVisible = true;

	return p_item;
}


void GI_initMutex() {
	mutex = xSemaphoreCreateMutex();
}

bool GI_take(GraphicItem_t *p_item) {
	xSemaphoreTake(mutex, portMAX_DELAY);
	bool ret = p_item->isAvailable;
	p_item->isAvailable = false;
	xSemaphoreGive(mutex);
	return ret;
}


void GI_give(GraphicItem_t *p_item) {
	xSemaphoreTake(mutex, portMAX_DELAY);
	p_item->isAvailable = true;
	xSemaphoreGive(mutex);
}