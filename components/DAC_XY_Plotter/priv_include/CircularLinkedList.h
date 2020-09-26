#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include "GraphicItem.h"

GraphicItem_t* cll_current_item();
GraphicItem_t* cll_next_item();
GraphicItem_t* cll_prev_item();
GraphicItem_t* cll_get_item_byId(int id);

void cll_add_item(GraphicItem_t* p_item);
void cll_delete_item(GraphicItem_t* p_item);
void cll_delete_item_byId(int id);

#endif