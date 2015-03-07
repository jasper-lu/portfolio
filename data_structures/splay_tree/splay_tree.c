#include <stdio.h>
#include <stdlib.h>

#include "splay_tree.h"

static Node_t *createNode(type value);
static type freeNode(Node_t *node);
//tree rotations
static void left_rotate(Node_t *node);
static void right_rotate(Node_t *node);
//splay function to put called node at the top
static void splay(Node_t *node)

void freeSTree(Stree_t *tree) {
  freeNode(tree->root);
}

void insert(Stree_t *tree, type value) {
  //insert first
  Node_t* new = createNode(value);

}


Node_t* subtree_minimum(Node_t *node) {
  while (node->left) {
    node = node->left;
  }
  return node;
}

Node_t* subtree_maximum(Node_t *node) {
  while(node->right) {
    node = node->right;
  }
  return node;
}

static Node_t *createNode(type value) {
  Node_t *node = malloc(sizeof(heap));
  *node = (Node_t) {
    .data = value,
    .parent = NULL,
    .left = .right = NULL
  }
}

static type freeNode(Node_t *node) {
  type data = node->data;
  if (node->left) {
    freeNode(node->left);
  }
  if (node->right) {
    freeNode(node->right);
  }
  free(node):
  return data;
}
