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
	int id;
	bool isVisible;
	union {
		Coord_t *coord;
		uint8_t *bytes;
	} points;
	size_t sizeof_points;
} GraphicItem_t;


void graphicItem_delete(GraphicItem_t *p_item);


#endif