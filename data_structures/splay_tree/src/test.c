#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "splay_tree.h"

int main() {
  STree_t *tree = createSTree();
  insert(tree, 5);
  insert(tree, 6);
  insert(tree, 7);
  insert(tree, 3);
  insert(tree, 2);

  if (tree->root->data == 2) {
    printf("Test passed! ");
  } else {
    printf("Test failed! ");
  }
  printf("Root is %d. Expected: %d\n", tree->root->data, 2);

  find(tree, 3);

  printf("3 found. Root is now %d\n", tree->root->data);

  erase(tree, 3);
  printf("3 erased. Root is now %d\n", tree->root->data);

  printf("Max in tree is %d. Expected: %d\n", maximum(tree)->data, 7);

  printf("Min in tree is %d. Expected: %d\n", minimum(tree)->data, 2);

  freeSTree(tree);
  return 1;
}
