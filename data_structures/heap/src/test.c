#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "min_heap.h"

int main() {
  Heap_t *heap = create_heap();
  heap_push(heap, 5);
  heap_push(heap, 3);
  heap_push(heap, 8);
  heap_push(heap, 2);

  int index = 1;
  while (index <= heap->count) {
      int c = 0;
      while (c != index) {
        printf("%d ", heap->data[index + c - 1]);
        ++c;
      }
      index *= 2;
      printf("\n");
  }

  printf("There may be some wonky numbers because of malloc\n");

  return 1;
}
