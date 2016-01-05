#include <assert.h>
#include "ArrayUtilLib.c"

void test_for_create(){
	ArrayUtil array_util=create(4,5);
	assert(array_util.length==5);
}