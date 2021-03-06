#ifndef GRAPHIC_ITEM_H
#define GRAPHIC_ITEM_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Coord {
	uint8_t x;
	uint8_t y;
} Coord_t;

typedef struct GraphicItem {
	volatile bool isAvailable;
	
	volatile bool isVisible;
	union {
		Coord_t *coord;
		uint8_t *bytes;
	} points;
	size_t sizeof_points;

	volatile struct GraphicItem *p_next;
	volatile struct GraphicItem *p_prev;
} GraphicItem_t;

GraphicItem_t* GI_create_take();
void GI_delete(GraphicItem_t* p_item);
void GI_delete_all();

GraphicItem_t* GI_get_next_take();

void GI_initMutex();
bool GI_try_take(GraphicItem_t *p_item);
void GI_wait_take(GraphicItem_t *p_item);
void GI_giveBack(GraphicItem_t *p_item);

#endif