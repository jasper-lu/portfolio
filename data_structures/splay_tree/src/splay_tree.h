//default to left
#define COMPARE(a,b) ((a) > (b))

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

STree_t *createSTree();

void freeSTree(STree_t *tree);

void insert(STree_t *tree,type value);

Node_t *find(STree_t *tree, type value);

void erase(STree_t *tree, type value);

Node_t *minimum(STree_t *tree);

Node_t *maximum(STree_t *tree);
