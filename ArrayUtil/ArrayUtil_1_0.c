#include <stdio.h>
#include "ArrayUtilLib_1_0.h"

void test_for_create(){
	assert(array_util.length==5);
}

int main() {
	ArrayUtil array_util=create(4,5);
	test_for_create();
	return 0;
};