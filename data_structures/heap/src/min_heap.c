#include <stdio.h>
#include <stdlib.h>

#include "min_heap.h"

//change these two declarations to modify for idfferent types
#define COMPARE(a, b) ((a) >= (b))

static const int base_size = 4;

void heapify_helper(Heap_t* heap, int index);

Heap_t* create_heap() {
  Heap_t* heap = malloc(sizeof(heap));
  *heap = (Heap_t) {
    .size = base_size,
    .count = 0,
    //base size is 4 length array
    .data = malloc(sizeof(type) * base_size)
  };
  return heap;
}

void heap_push(Heap_t* heap, type value) {
  if (heap->size == heap->count) {
    //double the size
    heap->size *= 2;
    heap->data = realloc(heap->data, sizeof(type) * heap->size);
  }

  int index = heap->count;

  //while the parent is less than the data right now
  while (index != 0 && COMPARE(heap->data[index/2], value)) {
      //move the larger data down
      heap->data[index] = heap->data[index/2];
      index /= 2;
  }

  heap->count++;
  heap->data[index] = value;
}

type heap_pop(Heap_t* heap) {
  type min = heap->data[0];
  heap->data[0] = heap->data[--heap->count];
  heapify(heap);
  return min;
}

void heapify(Heap_t* heap) {
  //starts on 1, then subtracts
  heapify_helper(heap, 1);
}

void heapify_helper(Heap_t* heap, int index) {

}
