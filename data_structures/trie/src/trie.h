#define BASE 0

typedef int type;
typedef int bool;

typedef struct TNode {
    char key;
    type value;
    //opting for linked list style
    struct TNode *next, *children;
} TNode_t;

typedef struct Trie {
    TNode_t *root;
} Trie_t;

Trie_t *createTrie();
void destroyTrie(Trie_t *trie);

TNode_t *add(Trie_t *trie, char *key, type value);
bool isMember(Trie_t *trie, char *key);
type find(Trie_t *trie, char *key);
type trieRemove(Trie_t *trie, char *key);
