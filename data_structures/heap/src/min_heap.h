typedef int type;

typedef struct Heap {
  int size; //memory size
  int count; //how many elements
  type *data; //array with numbers
} Heap_t;

//creates the heap
Heap_t* create_heap();

//adds a new value to the heap
void heap_push(Heap_t *heap, type value);

//removes the minimum value in heap
type heap_pop(Heap_t *heap);

//heapifies an array
void heapify(Heap_t *heap);
