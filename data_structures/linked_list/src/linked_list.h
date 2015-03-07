typedef struct LNode {
  void *data;
  struct LNode *next;
} LNode_t;

typedef struct LList {
  int len;
  LNode_t *head, *tail;
  //needs custom destroy for nodes because of void pointer data
  void (*destroy)(void *data);
} LList_t;

LList_t *createLList(void (*destroy)(void *data));

void freeLList(LList_t *list);

//insert in the front
void insert(LList_t *list, void *data);

//insert at a certain index
void insertAtIndex(LList_t *list, int index, void *data);

//insert after a node
void insertAfterLNode(LList_t *list, LNode_t *node, void *data);

//insert at end
void append(LList_t *list, void* data);

//remove from front
void *removeFirst(LList_t *list);

//remove from end
void *removeLast(LList_t *list);

//remove from index
void *removeAtIndex(LList_t *list, int index);

//remove after a node
void *removeAfterLNode(LList_t *list, LNode_t *node);

void printLList(LList_t* list);
