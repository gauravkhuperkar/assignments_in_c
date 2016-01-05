#include <stdio.h>
#include "ArrayUtilLib.h"

int main() {
	ArrayUtil array_util_1 = create(4,5);
	ArrayUtil array_util_2 = resize(array_util_1,8);
	printf("priviously length %d.....after length %d\n",array_util_1.length,array_util_2.length);
	return 0;
};