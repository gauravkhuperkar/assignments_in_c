typedef struct {
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);

int areEqual(ArrayUtil a, ArrayUtil b);

ArrayUtil resize(ArrayUtil util, int length);

int findIndex(ArrayUtil util, void* element);

void my_print(ArrayUtil util);

void dispose(ArrayUtil util);

typedef int (MatchFunc)(void*, void*);

int isMatch(void* ,void*);

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);

void* findLast(ArrayUtil util, MatchFunc* match, void* hint);

int count(ArrayUtil util, MatchFunc* match, void* hint);