#include <stdio.h>
#include "ArrayUtilLib.h"

int main() {
	int a = 0;
	ArrayUtil array_util_1 = create(4,4);
	ArrayUtil array_util_2 = resize(array_util_1,8);
	int index = findIndex(array_util_1, &a);
	printf("index is %d\n", index);
	printf("priviously length %d.....after length %d\n",array_util_1.length,array_util_2.length);
	return 0;
};