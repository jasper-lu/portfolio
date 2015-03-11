#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

int main() {
  Trie_t * trie = createTrie();
  add(trie, "ann", 5);
  add(trie, "anne", 5);
  add(trie, "anner", 15);
  add(trie, "e", 10);
  TNode_t *node = trie->root;

  printf("%c", node->key);
  node = node->children;
  printf("%c", node->key);
  node = node->children;
  printf("%c", node->key);
  node = node->children->next;
  printf("%c", node->key);
  node = node->children->next;
  printf("%c", node->key);

  printf(". expected: anner\n");

  printf("Node value is %d. Expected: %d\n", node->children->value, 15);

  printf("Find anne value. Value is %d. Expected: %d\n", find(trie, "anne"), 5);

  return 1;
}
