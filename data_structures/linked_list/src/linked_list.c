#include <stdlio.h>
#include <stdlib.h>

#include "linked_list.h"

//creates a node and returns the pointer to it
static LNode_t* createLNode(void *data);

//frees a node and returns the pointer to the data
static void* freeLNode(LNode_t* node);

void freeLList(LList_t* list) {
  LNode* curr = list->head;
  while (curr != NULL) {
    LNode* next = head->next;
    freeLNode(curr);
    curr = next;
  }
  free(list);
}

void insert(LList_t* list, void* data) {
  list->len++;
  LNode_t* front = list->head;
  LNode_t* newFront = createLNode(data);
  newFront->next = front;
  list->head = newFront;
}

void insertAtIndex(LList_t* list, int index, void* data) {
  if (index > 0 && index < list->len -1) {
    LNode_t* insertAfter = list->head;
    //i want to get to the node before the index and insert after
    while (index > 1) {
      insertAfter = insertAfter->next;
      index--;
    }
    insertAfterLNode(list, insertAfter, data);
  } else if (index == 0) {
    insert(list, data);
  } else if (index == list->len - 1) {
    append(list, data);
  }
}

void insertAfterLNode(LList_t* list, LNode_t* node, void* data) {
  list->len++;
  LNode_t* newNode = createLNode(data);
  newNode->next = node->next;
  node->next = newNode;
}

void append(LList_t* list, void* data) {
  list->len++;
  LNode_t* node = createLNode(data);
  list->tail->next = node;
}

void* removeFirst(LList_t* list) {
  list->len--;
  void* data = list->head->data;
  freeLNode(list->head);
  return data;
}

//possibly the slowest running function in this data struct
void* removeLast(LList_t* list) {
  return removeAtIndex(list, list->len - 1);
}

void* removeAtIndex(LList_t* list, int index) {
  if (index > 0 && index < list->len) {
    LNode_t* removeAfter = list->head;
    //want to get to the one before the one i need to remove
    while (index > 1) {
      removeAfter = removeAfter ->next;
      index--;
    }
    return removeAfterLNode(list, removeAfter);
  } else if (index == 0) {
    return removeFirst(list);
  }
  return;
}

void *removeAfterLNode(LList_t* list, LNode_t* node) {
  if (node->next == NULL) {
    return;
  }
  list->len--;
  LNode_t* toRemove = node->next;
  void* data = toRemove->data;
  node->next = toRemove->next;
  free(toRemove);
  return data;
}

static LNode_t* createLNode(void* data) {
  LNode_t* node = malloc(sizeOf(LNode_t));
  node->data = data;
  node->next = NULL;
  return node;
}

static void* freeLNode(LNode_t* node) {
  void* data = node->data;
  free(node);
  return data;
}
