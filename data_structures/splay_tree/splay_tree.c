#include <stdio.h>
#include <stdlib.h>

#include "splay_tree.h"

//tree rotations
static void left_rotate(Node_t *node);
static void right_rotate(Node_t *node);
//splay function to put called node at the top
static void splay(Node_t *node);

//util functions for nodes
static Node_t *createNode(type value);
static type freeNode(Node_t *node);

STree_t *createSTree() {
  Stree_t *tree = malloc(sizeof(STree_t));
  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void freeSTree(Stree_t *tree) {
  freeNode(tree->root);
}

void insert(Stree_t *tree, type value) {
  //insert first
  tree->size++;
  Node_t *current = tree->root;
  Node_t *parent = NULL;
  while(current) {
    parent = current;
    if (COMPARE(new->data, parent->data)) {
      current = current->right;
    } else {
      current = current->left;
    }
  }
  Node_t *new = createNode(value);
  new->parent = parent;
  if(!parent) {
    tree->root = new;
  }else {
    if (COMPARE(new->data, parent->data)) {
      parent->right = new;
    } else {
      parent->left = new;
    }
  }

  //splay
  splay(new);
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

//rotate node to top
static void left_rotate(STree_t *tree, Node_t *node) {
    Node_t *parent = node->parent;
    //exit if node is already root
    if (!parent) {
      return;
    }

    if (!parent->parent) {
      tree->root = node;
    } else if (parent == parent->parent->left) {
      parent->parent->left = node;
    } else {
      parent->parent->right = node;
    }

    //take care of parent changes
    node->parent = parent->parent;
    if (node->left) {
      node->left->parent = parent;
    }
    //transfer node's left
    parent->right = node->left

    //switch places of parent and child
    node->left = parent;
    parent->parent = node;
}

static void right_rotate(Node_t *node) {
  Node_t *parent = node->parent;
  //exit if node is already root
  if (!parent) {
    return;
  }

  if (!parent->parent) {
    tree->root = node;
  } else if (parent == parent->parent->left) {
    parent->parent->left = node;
  } else {
    parent->parent->right = node;
  }

  //take care of parent changes
  node->parent = parent->parent;
  if (node->right) {
    node->right->parent = parent;
  }
  //transfer node's left
  parent->left = node->right

  //switch places of parent and child
  node->right = parent;
  parent->parent = node;
}

static void splay(Node_t *node);

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
