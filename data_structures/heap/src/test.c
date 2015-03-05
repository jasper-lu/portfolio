#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

static void print_heap(Heap_t *heap) {
  int index = 0;
  while (index < heap->count) {
      int c = 0;
      while (c <= index) {
        printf("%d ", heap->data[index + c]);
        ++c;
      }
      index = index * 2 + 1;
      printf("\n");
  }
  printf("Count is: %d, Size is: %d\n", heap->count, heap->size);
}

int main() {
  Heap_t *heap = create_heap();
  heap_push(heap, 5);
  heap_push(heap, 3);
  heap_push(heap, 8);
  heap_push(heap, 2);
  heap_push(heap, 1);

  print_heap(heap);

  heap_pop(heap);
  heap_pop(heap);

  print_heap(heap);

  printf("There may be some wonky numbers because of malloc\n");

  return 1;
}
