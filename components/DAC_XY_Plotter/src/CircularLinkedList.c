#include "CircularLinkedList.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Cll_el {
	void* p_item ;
	struct Cll_el* prev;
	struct Cll_el *next;
} Cll_el_t;

static Cll_el_t *p_first_el = NULL;
static Cll_el_t *p_current_el = NULL;

static void      _cll_delete_el(Cll_el_t *p_el);

void* cll_current_item() {
	if(p_current_el == NULL) {
		return NULL;
	}
	return p_current_el->p_item;
}

void* cll_next_item() {
	//If no current element or it has no neighbour
	if(p_current_el == NULL || p_current_el->next == NULL) {
		//got to the first one
		p_current_el = p_first_el;
	} else {
		//move one step forward
		p_current_el = p_current_el->next;
	}

	if(p_current_el == NULL) {
		//The list is empty
		return NULL;
	}
	
	return p_current_el->p_item;
}

void* cll_prev_item() {
	//If no current element or it has no neighbour
	if(p_current_el == NULL || p_current_el->prev == NULL) {
		//got to the first one
		p_current_el = p_first_el;
	} else {
		//move one step backward
		p_current_el = p_current_el->prev;
	}

	if(p_current_el == NULL) {
		//The list is empty
		return NULL;
	}
	
	return p_current_el->p_item;
}

void cll_add(void* p_item) {
	Cll_el_t *new_element = calloc(1, sizeof(struct Cll_el));
	new_element->p_item = p_item;
	new_element->next = p_first_el;
	if(p_first_el != NULL) {
		p_first_el->prev = new_element;
	}
	p_first_el = new_element;
}

void _cll_delete_el(Cll_el_t *p_el) {
	if(p_el == NULL) {
		//no element found
		return;
	}

	if(p_el->prev == NULL) {
		p_first_el = p_el->next;
	} else {
		p_el->prev->next = p_el->next;
		if(p_el->next != NULL) {
			p_el->next->prev = p_el->prev;
		}
	}

	free(p_el);
}

bool cll_remove(void* p_item) {
	Cll_el_t *p_iterator = p_first_el;
	while(p_iterator != NULL) {
		if(p_iterator->p_item == p_item) {
			break;
		}
		p_iterator = p_iterator->next;
	}

	if(p_iterator == NULL) {
		//item not found
		return false;
	}

	_cll_delete_el(p_iterator);
	return true;
}