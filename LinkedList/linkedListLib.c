#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void *deleteElementAt(LinkedList *list, int index) {
	if(list->length <= index) return NULL;
	Element *p = list->first;
	if(index-1 == list->length) {
		for (int i = 0; i <= index-1; ++i) {
			p = p->next;
			list->last = p;
		};
		p->next = p->next->next;
		p = p->next;
		free(p->next);
		list->length--;
	}else if(index != 0){
		for (int i = 0; i < index-1; ++i)
			p = p->next;
		p->next = p->next->next;
		p = p->next;
		free(p->next);
		list->length--;
	}else if (index == 0){
		list->first = list->first->next;
		free(p->next);
		list->length--;
	};
	return p->value;
};

int asArray(LinkedList list, void **destination, int maxElements) {
	Element *element = list.first;
	int count = (list.length < maxElements) ? list.length : maxElements;
	for (int i = 0; i < count; ++i)	{
		memcpy((element->value), (destination + i), sizeof(element->value));
		element = element->next;
	};
	return count;
};


LinkedList reverse(LinkedList list) {
	LinkedList reversed  = createList();
	reversed.first = list.last;
	reversed.last = list.last;
	Element *ele = reversed.first; 
	for (int i = 0; i < list.length-1; ++i) {
		Element *e =   list.first;
		for (int j = 0; j < list.length - i; ++j) {
			e = e->next;
		};
		ele->next = e;
	};
	return reversed;
};

void addGivenNumber(void* hint, void* sourceItem, void* destinationItem) {
	*(int *)(destinationItem) = *((int *)(hint) + *(int *)(sourceItem));
};

LinkedList map(LinkedList list, ConvertFunc addGivenNumber, void * number) {
	LinkedList maped= createList();
	Element *element_1 = list.first;
	Element *element_2 = maped.first;
	for (int i = 0; i < list.length; ++i) {
		addGivenNumber(number, element_1, element_2);
		element_1 = element_1->next;
		element_2 = element_2->next;
	};
	return maped;
};