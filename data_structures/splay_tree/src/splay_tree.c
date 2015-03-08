#include <stdio.h>
#include <stdlib.h>

#include "splay_tree.h"

//subtree min/max

static Node_t *subtree_minimum(Node_t *node);
static Node_t *subtree_maximum(Node_t *node);

//tree rotations
static void left_rotate(STree_t *tree, Node_t *node);
static void right_rotate(STree_t *tree, Node_t *node);
//splay function to put called node at the top
static void splay(STree_t *tree, Node_t *node);

//util functions for nodes
static Node_t *createNode(type value);
static type freeNode(Node_t *node);
static type freeNodeR(Node_t *node);

STree_t *createSTree() {
  STree_t *tree = malloc(sizeof(STree_t));
  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void freeSTree(STree_t *tree) {
  freeNodeR(tree->root);
}

void insert(STree_t *tree, type value) {
  //insert first
  tree->size++;
  Node_t *current = tree->root;
  Node_t *parent = NULL;
  while(current) {
    parent = current;
    if (COMPARE(value, parent->data)) {
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
  splay(tree, new);
}

Node_t *find(STree_t *tree, type value) {
  Node_t *node = tree->root;
  while (node) {
    if (node->data == value) {
      //bring to top
      splay(tree, node);
      return node;
    } else if (COMPARE(value, node->data)) {
      node = node->right;
    } else {
      node = node->left;
    }
  }
  return NULL;
}

void erase(STree_t *tree, type value) {
  Node_t *node = find(tree, value);
  if (!node) {
    return;
  }
  Node_t *leftSubTree = node->left;
  Node_t *rightSubTree = node->right;
  freeNode(node);
  if (leftSubTree) {
    //find the max of the left subtree. this will fit as the new root
    Node_t *leftMax = subtree_maximum(leftSubTree);
    //set the roots and parnets
    tree->root = leftMax;
    leftSubTree->parent = leftMax;
    rightSubTree->parent = leftMax;

    //the parent's child is still the new root
    if (leftMax->parent->left == leftMax) {
      leftMax->parent->left = NULL;
    } else {
      leftMax ->parent->right = NULL;
    }

    //the new root needs to connect to the correct parents and children
    leftMax->parent = NULL;
    leftMax->right = rightSubTree;
    //don't want this to be circular if leftsubtree was already leftmax
    if (leftSubTree != leftMax) {
      leftMax->left = leftSubTree;
    }

  } else {
    tree->root = rightSubTree;
    rightSubTree->parent = NULL;
  }
}

Node_t *minimum(STree_t *tree) {
  return subtree_minimum(tree->root);
}

Node_t *maximum(STree_t *tree) {
  return subtree_maximum(tree->root);
}

static Node_t* subtree_minimum(Node_t *node) {
  while (node->left) {
    printf("Node is %d", node->data);
    node = node->left;
  }
  return node;
}

static Node_t* subtree_maximum(Node_t *node) {
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
    parent->right = node->left;

    //switch places of parent and child
    node->left = parent;
    parent->parent = node;
}

static void right_rotate(STree_t *tree, Node_t *node) {
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
  parent->left = node->right;

  //switch places of parent and child
  node->right = parent;
  parent->parent = node;
}

static void splay(STree_t *tree, Node_t *node) {
  while (node->parent) {
    if (!node->parent->parent) {
        if (node == node->parent->left) {
          right_rotate(tree, node);
        } else {
          left_rotate(tree, node);
        }
    } else if (node == node->parent->left && node->parent == node->parent->parent->left) {
      //zig zig
      right_rotate(tree, node->parent);
      right_rotate(tree, node);
    } else if (node == node->parent->left && node->parent == node->parent->parent->right) {
      //zig zag
      right_rotate(tree, node);
      left_rotate(tree, node);
    } else if (node == node->parent->right && node->parent == node->parent->parent->left) {
      //other zig zag
      left_rotate(tree, node);
      right_rotate(tree, node);
    } else {
      //other zig zig
      right_rotate(tree, node->parent);
      right_rotate(tree, node);
    }
  }
}

static Node_t *createNode(type value) {
  Node_t *node = malloc(sizeof(Node_t));
  *node = (Node_t) {
    .data = value,
    .parent = NULL,
    .left = NULL,
    .right = NULL,
  };
  return node;
}

///only removes the current node. may cause leaking memory if children aren't caught
static type freeNode(Node_t *node) {
  type data = node->data;
  free(node);
  return data;
}

static type freeNodeR(Node_t *node) {
  type data = node->data;
  if (node->left) {
    freeNodeR(node->left);
  }
  if(node->right) {
    freeNodeR(node->right);
  }
  free(node);
  return data;
}
