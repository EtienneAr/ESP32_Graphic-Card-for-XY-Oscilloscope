#include "GraphicItem.h"

void GI_delete(GI_uid_t uid) {
	GraphicItem_t *p_item = (GraphicItem_t*) uid;
	bool res = cll_remove(p_item);
	
	if(res) {
		if(p_item != NULL) {
			if(p_item->points.bytes != NULL) {
				free(p_item->points.bytes);
			}

			free(p_item);	
		}
	}
}

GI_uid_t GI_create() {
	GraphicItem_t *p_item = malloc(sizeof(GraphicItem_t));
	p_item->isVisible = true;

	cll_add(p_item);

	return (GI_uid_t) p_item;
}