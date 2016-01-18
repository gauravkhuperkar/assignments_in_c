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
	int element_1 = 12;
	int element_2 = 13;
	add_to_list(&list, &element_1);
	add_to_list(&list, &element_2);
	void *pointer = get_first_element(list);
	assert(*(int *)(pointer) == element_1);
};

void test_for_get_last_element() {
	LinkedList list  = createList();

	int element_1 = 12;
	int element_2 = 13;

	add_to_list(&list, &element_1);
	add_to_list(&list, &element_2);

	void *pointer = get_last_element(list);
	assert(*(int *)(pointer) == element_2);
};

void test_for_getElementAt() {
	LinkedList list  = createList();

	int element_1 = 12;
	int element_2 = 13;
	int element_3 = 23;

	add_to_list(&list, &element_1);
	add_to_list(&list, &element_2);
	add_to_list(&list, &element_3);

	void *ele_1 = getElementAt(list, 5);
	void *ele_2 = getElementAt(list, 1);
	void *ele_3 = getElementAt(list, 0);
	void *ele_4 = getElementAt(list, 2);

	assert(ele_1 == NULL);
	assert(*(int *)(ele_2) == element_2);
	assert(*(int *)(ele_3) == element_1);
	assert(*(int *)(ele_4) == element_3);
};

void test_for_inndexOf() {
	LinkedList list = createList();

	int element_1 = 12;
	int element_2 = 13;
	int element_3 = 24;

	add_to_list(&list, &element_1);
	add_to_list(&list, &element_2);
	add_to_list(&list, &element_3);
	int index = indexOf(list, &element_2);
	assert(index == 1);
};