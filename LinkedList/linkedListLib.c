#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

LinkedList createList(void) {
	LinkedList list;
	list.first = NULL;
	list.last = NULL;
	list.length = 0;
	return list;
};
                                            
int add_to_list(LinkedList *list, void *element) {
	Element *e = (Element *)malloc(sizeof(Element));
	e->value = element;
	e->next = NULL;
	if(!list->first) {
		list->first = e;
	}else{
		list->last->next = e;
	};
	list->last = e;
	list->length++;
	return list->length;
};

void *get_first_element(LinkedList list) {
	return list.first->value;
};

void *get_last_element(LinkedList list) {
	return list.last->value;
};

void forEach(LinkedList list, ElementProcessor e) {
	for (int i = 0; i < list.length; ++i) {
		e(list.first+i*sizeof(*list.first));
	};
};

void increment(void *pointer) {
	pointer++;
};

void *getElementAt(LinkedList list, int index) {
	if(index >= list.length) return NULL;
	Element *p = list.first;
	for (int i = 0; i < index; ++i) {
		p = p->next;
	};
	return p->value;
};

int indexOf(LinkedList list, void *element) {
	Element *p = list.first;
	for (int i = 0; i < list.length; ++i) {
		if(p->value == element) return i;
		p = p->next;
	};
	return -1;
};