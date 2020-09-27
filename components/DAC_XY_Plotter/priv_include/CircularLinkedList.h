#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdbool.h>

void* cll_current_item();
void* cll_next_item();
void* cll_prev_item();

void cll_add(void* p_item);
bool cll_remove(void* p_item);

#endif