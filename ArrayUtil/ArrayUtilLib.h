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

int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

void square(void* hint, void* sourceItem, void* destinationItem);

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

typedef void OperationFunc(void* hint, void* item);

void addNumber(void* hint, void* item);

void forEach(ArrayUtil util, OperationFunc* operation, void* hint);