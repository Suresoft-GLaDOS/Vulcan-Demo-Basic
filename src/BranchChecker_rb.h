#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>

enum nodeColor {
  RED,
  BLACK
};

struct rbNode {
  int data, color;
  struct rbNode *link[2];
};

struct rbNode *createNode(int data);
struct rbNode* insertion(struct rbNode* node, int data);
struct rbNode* deletion(struct rbNode* node, int data);
void inorderTraversal(struct rbNode* node, int* result);
int* getInorderTraversal(struct rbNode* node);