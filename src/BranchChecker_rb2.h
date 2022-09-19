#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>


typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct Node_RB {
  color_t color;
  key_t data;
  struct Node_RB *parent, *left, *right;
} Node_RB;

typedef struct {
  Node_RB *root;
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);

Node_RB *rbtree_insert(rbtree *, key_t);
Node_RB *rbtree_find(const rbtree *, const key_t);
Node_RB *rbtree_min(const rbtree *);
Node_RB *rbtree_max(const rbtree *);
int rbtreeDelete(rbtree *, Node_RB *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);


void *insert_fixup(rbtree *, Node_RB *);
void *delete_fixup(rbtree *, Node_RB *);

void rb_inorder(Node_RB* node, int* result);
int* rb_get_inorder(Node_RB* node);