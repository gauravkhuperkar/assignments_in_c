#include <stdio.h>
#include "ArrayUtilLib.h"
#include <string.h>
#include <stdlib.h>

int main() {
	int a = 2;
	int b = 2;
	int c = 23;
	int d = 0;
	ArrayUtil array_util_1 = create(4,4);
	ArrayUtil array_util_2 = resize(array_util_1,8);
	int index = findIndex(array_util_1, &a);
	void *q = findFirst(array_util_1, &isMatch, &a);
	void *p = findLast(array_util_1, &isMatch, &a);
	int s = count(array_util_1, &isMatch, &a);
	int t = count(array_util_1, &isMatch, &d);
	int g = filter(array_util_2, &isMatch, &a, array_util_1.base, 4);
	dispose(array_util_1);
	printf("index is %d\n", index);
	printf("priviously length %d.....after length %d.........%d\n",array_util_1.length,array_util_2.length,g);
	int x = isMatch(&a, &b);
	int y = isMatch(&a, &c);
	printf("should 1 : %d............ should 0 : %d.. should 0 and is : %d.... should 4 and is : %d\n",x,y,s,t);
	return 0;
};