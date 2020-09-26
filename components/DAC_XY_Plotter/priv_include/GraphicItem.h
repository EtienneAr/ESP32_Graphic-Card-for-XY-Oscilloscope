#ifndef GRAPHIC_ITEM_H
#define GRAPHIC_ITEM_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct GraphicItem {
	int id;
	bool isVisible;
	uint8_t* points;
	size_t sizeof_points;
} GraphicItem_t;


void graphicItem_delete(GraphicItem_t *p_item);


#endif