#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"
#include <string.h>

void test_for_createList() {
	LinkedList list = createList();
	assert(list.length == 0);
	assert(list.first == NULL);
	assert(list.last == NULL);
};

void test_for_add_to_list() {
	LinkedList list  = createList();
	Element *element = (Element *)malloc(sizeof(Element));
	element->value = (void *)12;
	int length = add_to_list(&list, element);
	assert(list.length == 1);
	assert(*(int *)(list.first->value) == 12);
	assert(*(int *)(list.last->value) == 12);
	assert(list.last->next == NULL);
};

void test_for_get_first_element() {
	LinkedList list  = createList();
	Element *element_1 = (Element *)malloc(sizeof(Element));
	Element *element_2 = (Element *)malloc(sizeof(Element));
	add_to_list(&list, element_1);
	add_to_list(&list, element_2);
	void *pointer = get_first_element(list);
	printf(">>>>>>>>>>>>>>>> pointer is : %p & element is : %p", pointer,element_1);
	assert(pointer == element_1);
};

void test_for_get_last_element() {
	LinkedList list  = createList();
	Element *element_1 = (Element *)malloc(sizeof(Element));
	Element *element_2 = (Element *)malloc(sizeof(Element));
	add_to_list(&list, element_1);
	add_to_list(&list, element_2);
	void *pointer = get_last_element(list);
	printf(">>>>>>>>>>>>>>>> pointer is : %p & element is : %p", pointer,element_1);
	assert(pointer == element_2);
};