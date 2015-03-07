//default to left
#define COMPARE(a,b) ((a) >= (b))

typedef int type;

typedef struct Node {
  type data;
  struct Node *parent;
  struct Node *left, *right;
} Node_t;

typedef struct STree {
  Node_t *root;
  type size;
} STree_t;

void freeSTree(Stree_t *tree);

void insert(Stree_t *tree,type value);

Node_t* find(Stree_t *tree, type value);

Node_t* erase(Stree_t *tree, type value);

Node_t* minimum(Stree_t *tree);

Node_t* maximum(Stree_t *tree);
