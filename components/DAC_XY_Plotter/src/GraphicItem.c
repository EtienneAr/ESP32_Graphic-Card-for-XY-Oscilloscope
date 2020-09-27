#include "GraphicItem.h"

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
	p_item->isVisible = true;

	return p_item;
}