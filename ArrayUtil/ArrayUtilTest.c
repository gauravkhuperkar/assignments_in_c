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

void test_for_findFirst() {
	ArrayUtil array_util = create(4,5);
	int num = 21;
	int *array = ( int *)array_util.base;
	array[0] = 21;
	array[1] = 37;
	array[2] = 401;
	array[3] = 21;
	array[4] = 81;
	int *frist = (int *)findFirst(array_util, &isMatch, &num);
	assert(*frist == 21);
};

void test_for_findLast() {
	ArrayUtil array_util = create(4,5);
	int num1 = 17;
	int num2 = 21;
	int *array = ( int *)array_util.base;
	array[0] = 21;
	array[1] = 37;
	array[2] = 401;
	array[3] = 21;
	array[4] = 81;
	int *last1 = findLast(array_util, &isMatch, &num1);
	int *last2 = findLast(array_util, &isMatch, &num2);
	assert(last1 == NULL);
	assert(*last2 == 21);
};

void test_for_filter() {
	ArrayUtil array_util_1 = create(4,5);
	ArrayUtil array_util_2 = create(4,5);
	int a = 0;
	int b = 12;
	int noOfMatches_1 = filter(array_util_1, &isMatch, &a, array_util_2.base, 4);
	int noOfMatches_2 = filter(array_util_1, &isMatch, &b, array_util_2.base, 4);
	assert(noOfMatches_1 == 5);
	assert(noOfMatches_2 == 0);
};

void test_for_map() {
	ArrayUtil array_util_1 = create(4,5);
	ArrayUtil array_util_2 = create(4,5);
	int num = 21;
	int *array_1 = ( int *)array_util_1.base;
	int *array_2 = ( int *)array_util_2.base;
	array_1[0] = 3;
	array_1[1] = 8;
	array_1[2] = 40;
	array_1[3] = 21;
	array_1[4] = 32;
	map(array_util_1, array_util_2, &square, &num);
	assert(array_1[0] == 3);
	assert(array_2[0] == 9);
	assert(array_2[1] == 64);
	assert(array_2[2] == 1600);
	assert(array_2[3] == 441);
	assert(array_2[4] == 1024);
};

void test_for_forEach() {
	int number = 2;
	ArrayUtil array_util = create(4,5);
	int *array = (int *)array_util.base;
	array[0] = 3;
	array[1] = 8;
	array[2] = 40;
	array[3] = 21;
	array[4] = 32;
	forEach(array_util, &addNumber, &number);
	assert(array[0] == 5);
	assert(array[1] == 10);
	assert(array[2] == 42);
	assert(array[3] == 23);
	assert(array[4] == 34);
};
