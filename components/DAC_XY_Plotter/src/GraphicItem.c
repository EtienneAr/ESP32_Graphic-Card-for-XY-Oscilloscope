#include "GraphicItem.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

SemaphoreHandle_t availabilityMutex;
SemaphoreHandle_t linkedlistMutex;

static GraphicItem_t *p_first_item = NULL;
static GraphicItem_t *p_next_item = NULL;

GraphicItem_t* _new_GI();
void _delete_GI(GraphicItem_t* p_item);

GraphicItem_t* _new_GI() {
	GraphicItem_t *p_item = calloc(1, sizeof(GraphicItem_t));
	p_item->isVisible = true;

	return p_item;
}

void _delete_GI(GraphicItem_t* p_item) {
	if(p_item != NULL) {
		if(p_item->points.bytes != NULL) {
			free(p_item->points.bytes);
		}
		free(p_item);
	}
}

GraphicItem_t* GI_create_take() {
	GraphicItem_t *p_item = _new_GI();
	p_item->isAvailable = false;
	
	xSemaphoreTake(linkedlistMutex, portMAX_DELAY);
	/* insert the item at the beginnnig of the list */
	if(p_first_item != NULL) {
		p_first_item->p_prev = p_item;
	}
	p_item->p_next = p_first_item;
	p_first_item = p_item;
	xSemaphoreGive(linkedlistMutex);

	return p_item;
}

void GI_delete(GraphicItem_t* p_item) {
	if(p_item == NULL) {
		return;
	}

	//take the Item
	GI_wait_take(p_item);

	xSemaphoreTake(linkedlistMutex, portMAX_DELAY);
	//Change first element of the list if necessary
	if(p_first_item == p_item) {
		p_first_item = p_item->p_next;
	}

	//Move current pointer is necessary
	if(p_next_item == p_item) {
		p_next_item = p_item->p_next;
	}

	//Cut / glue list
	if(p_item->p_prev != NULL) {
		p_item->p_prev->p_next = p_item->p_next;
	}
	if(p_item->p_next != NULL) {
		p_item->p_next->p_prev = p_item->p_prev;
	}
	xSemaphoreGive(linkedlistMutex);

	_delete_GI(p_item);
}

/* This function actually return the current item and move the pointer to one forward */
GraphicItem_t* GI_get_next_take() {
	GraphicItem_t* ret;

	xSemaphoreTake(availabilityMutex, portMAX_DELAY);
	xSemaphoreTake(linkedlistMutex, portMAX_DELAY);
	do {
		//Return the current
		ret = p_next_item;

		//Move the next item
		if(p_next_item == NULL || p_next_item->p_next == NULL) {
			//go to the first one
			p_next_item = p_first_item;
		} else {
			//move one step forward
			p_next_item = p_next_item->p_next;
		}
	} while(ret != NULL && !ret->isAvailable); //While there is a next element and this one taken already

	if(ret != NULL) {
		ret->isAvailable = false;
	}
	xSemaphoreGive(linkedlistMutex);
	xSemaphoreGive(availabilityMutex);

	return ret;
}

void GI_initMutex() {
	availabilityMutex = xSemaphoreCreateMutex();
	linkedlistMutex = xSemaphoreCreateMutex();
}

void GI_wait_take(GraphicItem_t *p_item) {
	while(!GI_try_take(p_item)) {
		vTaskDelay(1);
	}
}

bool GI_try_take(GraphicItem_t *p_item) {
	xSemaphoreTake(availabilityMutex, portMAX_DELAY);
	bool ret = p_item->isAvailable;
	p_item->isAvailable = false;
	xSemaphoreGive(availabilityMutex);
	return ret;
}


void GI_giveBack(GraphicItem_t *p_item) {
	//xSemaphoreTake(availabilityMutex, portMAX_DELAY);
	p_item->isAvailable = true;
	//xSemaphoreGive(availabilityMutex);
}