#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* Parent, * Left, * Right;
}Node;

int GetHeight(Node* node);
int CalculateBalanceFactor(Node* node);
Node* RR(Node* node);
Node* LL(Node* node);
Node* LR(Node* node);
Node* RL(Node* node);
Node* AVLSet(Node* node);
Node* Insert(Node* node, int data);
Node* arrInsert(Node* node, int data1,
                            int data2,
                            int data3,
                            int data4,
                            int data5,
                            int data6,
                            int data7,
                            int data8,
                            int data9,
                            int data10,
                            int data11);
Node* GetMinNode(Node* node, Node* parent);
Node* Delete(Node* node, int data);
Node* arrDelete(Node* node, int data1,
                            int data2,
                            int data3);
void Inorder(Node* node, int* result);
int* getInorder(Node* node);

