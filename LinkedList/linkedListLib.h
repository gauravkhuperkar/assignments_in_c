typedef struct element {
	void *value;
	struct element *next;
} Element;

typedef struct{
	Element *first;
	Element *last;
	int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList createList(void);

int add_to_list(LinkedList *,void *);

void print(LinkedList list);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

void forEach(LinkedList, ElementProcessor e);

void increment(void *);

void *getElementAt(LinkedList, int );

int indexOf(LinkedList, void *);

void *deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **, int maxElements);

LinkedList reverse(LinkedList);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

LinkedList map(LinkedList, ConvertFunc, void * );

typedef void* Reducer(void* hint, void* previousItem, void* item);

LinkedList reduce(LinkedList, Reducer, void *hint, void *initialValue);