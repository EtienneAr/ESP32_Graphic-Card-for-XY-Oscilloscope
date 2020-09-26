#include "GraphicItem.h"

void graphicItem_delete(GraphicItem_t *p_item) {
	if(p_item == NULL) {
		return;
	}
	
	if(p_item->points.bytes != NULL) {
		free(p_item->points.bytes);
	}

	free(p_item);	
}