#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

static TNode_t *createTNode(char key, type value);
static TNode_t *findNode(Trie_t *trie, char *key);
static void freeTNodeR(TNode_t *node);

Trie_t *createTrie() {
  Trie_t *trie = malloc(sizeof(Trie_t));
  trie->root = NULL;
  return trie;
}

void destroyTrie(Trie_t *trie) {
  freeTNodeR(trie->root);
}

//char arrays must be null terminated
TNode_t *add(Trie_t *trie, char *key, type value) {
  int index = 0;
  TNode_t *curr = trie->root;
  TNode_t *from = NULL;
  //go up to the point where the keys don't match any more
  while (curr) {
    //check if key still exists
    if (!key[index]) {
      break;
    }
    //find matching key
    if (curr->key == key[index]) {
      index++;
      from = curr;
      curr = curr->children;
    } else {
      from = curr;
      curr = curr->next;
    }
  }

  if (!from) {
    trie->root = createTNode(key[index++], BASE);
    from = trie->root;
    curr = from->children;
  } else {
    from->next = createTNode(key[index++], BASE);
    from = from->next;
  }

  //now just fill it
  while (key[index]) {
    from->children = createTNode(key[index], BASE);
    from = from->children;
    index++;
  }

  //null node
  from->children = createTNode('\0', value);
  return from->children;
}

bool isMember(Trie_t *trie, char *key) {
  return findNode(trie, key) != NULL;
}

type find(Trie_t *trie, char *key) {
  TNode_t *node = findNode(trie, key);
  if (!node) {
    return 0;
  }
  return node->value;
}

//will always contain the key
bool trieRemoveHelper(TNode_t *node, TNode_t *from, char *key, int index) {
  if (node) {
    //base
    if (node->key == '\0') {
      if (node->next && from->children == node) {
        from->children = node->next;
      }
      free(node);
      return true;
    } else {
      while (node->key != key[index]) {

      }
    }
  }
  return false;
}

type trieRemove(Trie_t *trie, char *key) {
  if (!findNode(trie, key)) {
    return 0;
  }

}

static TNode_t *createTNode(char key, type value) {
  TNode_t *new = malloc(sizeof(TNode_t));
  new->key = key;
  new->value = value;
  new->next = new->children = NULL;
  return new;
}

static TNode_t *findNode(Trie_t *trie, char *key) {
  int index = 0;
  TNode_t *curr = trie->root;
  while (key[index]) {
    if (!curr) {
      break;
    }
    if (curr->key == key[index]) {
      curr = curr->children;
      index++;
    } else {
      curr = curr->next;
    }
  }
  return curr;
}

static void freeTNodeR(TNode_t *node) {
  if (node->next) {
    freeTNodeR(node->next);
  }
  if (node->children) {
    freeTNodeR(node->children);
  }
  free(node);
}
