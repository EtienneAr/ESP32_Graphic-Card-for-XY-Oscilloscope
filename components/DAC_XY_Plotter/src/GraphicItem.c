#include "GraphicItem.h"

void graphicItem_delete(GraphicItem_t *p_item) {
	if(p_item == NULL) {
		return;
	}
	
	if(p_item->points != NULL) {
		free(p_item->points);
	}

	free(p_item);	
}