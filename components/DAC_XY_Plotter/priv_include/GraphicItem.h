#ifndef GRAPHIC_ITEM_H
#define GRAPHIC_ITEM_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct graphicItem {
	int id;
	bool isVisible;
	uint8_t* points;
	size_t sizeof_points;
} graphicItem_t;


void graphicItem_delete(graphicItem_t *p_item) {
	if(p_item == NULL) {
		return;
	}
	
	if(p_item->points != NULL) {
		free(p_item->points);
	}

	free(p_item);	
}

#endif