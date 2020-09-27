#include "GraphicItem.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

SemaphoreHandle_t mutex;

static GraphicItem_t *p_first_item = NULL;
static GraphicItem_t *p_current_item = NULL;

GraphicItem_t* _new_GI();
void _delete_GI(GraphicItem_t* p_item);

GraphicItem_t* _new_GI() {
	GraphicItem_t *p_item = calloc(1, sizeof(GraphicItem_t));
	p_item->isVisible = true;

	return p_item;
}

void _delete_GI(GraphicItem_t* p_item) {
	if(p_item->points.bytes != NULL) {
		free(p_item->points.bytes);
	}
	free(p_item);
}

GraphicItem_t* GI_create_take() {
	GraphicItem_t *p_item = _new_GI();
	p_item->isAvailable = false;
	
	/* insert the item at the beginnnig of the list */
	if(p_first_item != NULL) {
		p_first_item->p_prev = p_item;
	}
	p_item->p_next = p_first_item;
	p_first_item = p_item;

	return p_item;
}

void GI_delete(GraphicItem_t* p_item) {
	if(p_item == NULL) {
		return;
	}

	//Move current pointer is necessary
	if(p_current_item == p_item) {
		p_current_item = p_item->p_next;
	}

	//Cut / glue list
	if(p_item->p_prev != NULL) {
		p_item->p_prev->p_next = p_item->p_next;
	}
	if(p_item->p_next != NULL) {
		p_item->p_next->p_prev = p_item->p_prev;
	}
	if(p_first_item == p_item) {
		p_first_item = p_item->p_next;
	}

	_delete_GI(p_item);
}

GraphicItem_t* GI_get_next() {
	//If no current element or it has no neighbour
	if(p_current_item == NULL || p_current_item->p_next == NULL) {
		//got to the first one
		p_current_item = p_first_item;
	} else {
		//move one step forward
		p_current_item = p_current_item->p_next;
	}
	
	return p_current_item;
}

void GI_initMutex() {
	mutex = xSemaphoreCreateMutex();
}

void GI_wait_take(GraphicItem_t *p_item) {
	while(!GI_try_take(p_item)) {
		vTaskDelay(1);
	}
}

bool GI_try_take(GraphicItem_t *p_item) {
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