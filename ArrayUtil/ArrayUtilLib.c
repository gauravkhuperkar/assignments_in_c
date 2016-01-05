#include "ArrayUtilLib.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length) {
	ArrayUtil array_util;
	array_util.base = calloc(length,sizeof(typeSize));
	array_util.typeSize = typeSize;
	array_util.length = length;
	return array_util;
};

int areEqual(ArrayUtil a, ArrayUtil b) {
	if(a.length == b.length && a.typeSize == b.typeSize) {
		char *ele1 = a.base;
		char *ele2 = b.base;
		for (int i = 0; i < a.length*a.typeSize; i++)
			if (ele1[i]!=ele2[i]) return 0;
		return 1;
	}
	else return 0;
};

ArrayUtil resize(ArrayUtil util, int length) {
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
};