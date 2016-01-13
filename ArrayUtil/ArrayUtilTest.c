#include <assert.h>
#include <stdio.h>
#include "ArrayUtilLib.h"
#include <string.h>

void test_for_create() {
	ArrayUtil array_util = create(4,5);
	assert(array_util.length==5);
	assert(array_util.typeSize==4);
};

void test_for_resize() {
	ArrayUtil array_util_1 = create(4,4);
	ArrayUtil array_util_2 = resize(array_util_1,8);
	assert(array_util_1.length == 4);
	assert(array_util_2.length == 8);
};

void test_for_findIndex() {
	ArrayUtil array_util = create(4,4);
	int a = 20;
	int b = 0;
	int index_1 = findIndex(array_util, &a);
	int index_2 = findIndex(array_util, &b);
	assert(index_1 == -1);
	assert(index_2 == 0);
};