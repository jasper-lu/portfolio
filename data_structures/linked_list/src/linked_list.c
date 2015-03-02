#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

//creates a node and returns the pointer to it
static LNode_t* createLNode(void *data);

//frees a node and returns the pointer to the data
static void* freeLNode(LNode_t* node);

LList_t *createLList(void (*destroy)(void* data)) {
  LList_t* list = malloc(sizeof(LList_t));
  list->len = 0;
  list->head = list->tail = NULL;
  list->destroy = destroy;
  return list;
}

void freeLList(LList_t* list) {
  LNode_t *curr = list->head;
  while (curr != NULL) {
    LNode_t *next = curr->next;
    freeLNode(curr);
    curr = next;
  free(list);
  }
}

void insert(LList_t* list, void* data) {
  list->len++;
  LNode_t* front = list->head;
  LNode_t* newFront = createLNode(data);
  newFront->next = front;
  list->head = newFront;

  if (list->tail == NULL) {
    list->tail = newFront;
  }
}

void insertAtIndex(LList_t* list, int index, void* data) {
  if (index > 0 && index < list->len) {
    LNode_t* insertAfter = list->head;
    //i want to get to the node before the index and insert after
    while (index > 1) {
      insertAfter = insertAfter->next;
      index--;
    }
    insertAfterLNode(list, insertAfter, data);
  } else if (index == 0) {
    insert(list, data);
  } else if (index == list->len) {
    append(list, data);
  }
}

void insertAfterLNode(LList_t* list, LNode_t* node, void* data) {
  list->len++;
  LNode_t* newNode = createLNode(data);
  newNode->next = node->next;
  node->next = newNode;

  if (node == list->tail) {
    list->tail = newNode;
  }
}

void append(LList_t* list, void* data) {
  list->len++;
  LNode_t* node = createLNode(data);
  list->tail->next = node;
  list->tail = node;
}

void* removeFirst(LList_t* list) {
  list->len--;
  LNode_t* toRemove = list->head;
  list->head = toRemove->next;

  if (toRemove == list->tail) {
    list->tail = NULL;
  }

  return freeLNode(list->head);
}

//possibly the slowest running function in this data struct
void* removeLast(LList_t* list) {
  //if there's only one node left, it's much easier to do it this way
  if (list->len == 1) {
    LNode_t* node = list->tail;
    list->len--;
    list->head = list->tail = NULL;
    return freeLNode(node);
  }
  return removeAtIndex(list, list->len - 1);
}

void* removeAtIndex(LList_t* list, int index) {
  if (index > 0 && index < list->len) {
    LNode_t* removeAfter = list->head;
    //want to get to the one before the one i need to remove
    while (index > 1) {
      removeAfter = removeAfter->next;
      index--;
    }
    return removeAfterLNode(list, removeAfter);
  } else if (index == 0) {
    return removeFirst(list);
  }
  return NULL;
}

//will assume that the node passed will never be tail
void *removeAfterLNode(LList_t *list, LNode_t *node) {
  list->len--;
  LNode_t *toRemove = node->next;
  if (toRemove == list->tail) {
    list->tail = node;
  }
  node->next = toRemove->next;
  return freeLNode(toRemove);
}

static LNode_t* createLNode(void *data) {
  LNode_t* node = malloc(sizeof(LNode_t));
  node->data = data;
  node->next = NULL;
  return node;
}

static void* freeLNode(LNode_t *node) {
  void* data = node->data;
  free(node);
  return data;
}

void printLList(LList_t *list) {
  LNode_t *curr = list->head;
  while(curr != NULL) {
    printf("%s->", (char *)curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}
