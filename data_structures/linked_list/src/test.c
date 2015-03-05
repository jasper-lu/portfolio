#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

//change this declaration for different linked list data types 
static void freeData(void* data) {
  free((char* )data);
}

static void testLList() {
  char* chars[4];
  int i;
  for (i = 0; i < 4; ++i) {
    chars[i] = malloc(2);
    sprintf(chars[i], "%d", i);
  }

  LList_t* list = createLList(freeData);
  insert(list, chars[0]);
  insertAtIndex(list, 1, chars[1]);
  insertAfterLNode(list, list->tail, chars[2]);
  append(list, chars[3]);

  printLList(list);

  removeFirst(list);
  removeAtIndex(list, 1);
  removeAfterLNode(list, list->head);
  removeLast(list);

  printLList(list);
}

int main() {
  testLList();
  return 1;
}
