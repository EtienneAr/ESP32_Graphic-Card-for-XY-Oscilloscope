#ifndef GRAPHIC_ITEM_H
#define GRAPHIC_ITEM_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "CircularLinkedList.h"


typedef struct Coord {
	uint8_t x;
	uint8_t y;
} Coord_t;

typedef struct GraphicItem {
	bool isAvailable;
	bool isVisible;
	union {
		Coord_t *coord;
		uint8_t *bytes;
	} points;
	size_t sizeof_points;
} GraphicItem_t;

GraphicItem_t* GI_create();
void GI_delete(GraphicItem_t* p_item);

void GI_initMutex();
bool GI_take(GraphicItem_t *p_item);
void GI_give(GraphicItem_t *p_item);

#endif