#include <stdio.h>
#include <stdlib.h>

#include "min_heap.h"

//change these two declarations to modify for idfferent types
#define COMPARE(a, b) ((a) >= (b))

static const int base_size = 4;

Heap_t* create_heap() {
  Heap_t* heap = malloc(sizeof(heap));
  *heap = (Heap_t) {
    .size = 0,
    .count = 0,
    .data = malloc(base_size)
  };
  return heap;
}
