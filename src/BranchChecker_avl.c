#include <stdio.h>
#include "BranchChecker_avl.h"

int curIndex = 0;

int GetHeight(Node* node)
{
    if (node == NULL) return 0;

    int leftDepth = GetHeight(node->Left);
    int rightDepth = GetHeight(node->Right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int CalculateBalanceFactor(Node* node)
{
    return GetHeight(node->Left) - GetHeight(node->Right);
}

Node* RR(Node* node)
{
    Node* childNode = node->Right;
    node->Right = childNode->Left;
    if (childNode->Left != NULL)
        childNode->Left->Parent = node;

    childNode->Left = node;
    childNode->Parent = node->Parent;
    node->Parent = childNode;

    return childNode;
}

Node* LL(Node* node)
{
    Node* childNode = node->Left;
    node->Left = childNode->Right;
    if (childNode->Right != NULL)
        childNode->Right->Parent = node;

    childNode->Right = node;
    childNode->Parent = node->Parent;
    node->Parent = childNode;

    return childNode;
}

Node* LR(Node* node)
{
    node->Left = RR(node->Left);
    return LL(node);
}

Node* RL(Node* node)
{
    node->Right = LL(node->Right);
    return RR(node);
}

Node* AVLSet(Node* node)
{
    int depth = CalculateBalanceFactor(node);
    if (depth >= 2)
    {
        depth = CalculateBalanceFactor(node->Left);
        if (depth >= 1)
        {
            //LL : Left Left
            node = LL(node);
        }
        else
        {
            //LR : Left Right
            node = LR(node);
        }
    }
    else if (depth <= -2)
    {
        depth = CalculateBalanceFactor(node->Right);
        if (depth <= -1)
        {
            //RR : Right Right
            node = RR(node);
        }
        else
        {
            //RL : Right Left
            node = RL(node);
        }

    }

    return node;
}

Node* Insert(Node* node, int data)
{
    if (node == NULL)
    {
        node = (Node*)malloc(sizeof(Node));
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
        node->data = data;

        return node;
    }
    else if (data < node->data)
    {
        node->Left = Insert(node->Left, data);
        node->Left->Parent = node;
        node = AVLSet(node);
    }
    else if (data > node->data)
    {
        node->Right = Insert(node->Right, data);
        node->Right->Parent = node;
        node = AVLSet(node);
    }
    else
    {
        //Do not add data to avoid duplication. but?
//        node->Right = Insert(node->Right, data);
//        node->Right->Parent = node;
//        node = AVLSet(node);
    }

    return node;
}

Node* GetMinNode(Node* node, Node* parent)
{
    if (node->Left == NULL)
    {
        if (node->Parent != NULL)
        {
            if (parent != node->Parent)
            {
                node->Parent->Left = node->Right;
            }
            else
            {
                node->Parent->Right = node->Right;
            }

//            node->Right->Parent = node->Parent;
            if (node->Right != NULL)
            {
                node->Right->Parent = node->Parent;
            }
        }

        return node;
    }
    else
    {
        return GetMinNode(node->Left, parent);
    }
}

Node* Delete(Node* node, int data)
{
    if (node == NULL) return NULL;

    if (data < node->data)
    {
        node->Left = Delete(node->Left, data);
        node = AVLSet(node);
    }
    else if (data > node->data)
    {
        node->Right = Delete(node->Right, data);
        node = AVLSet(node);
    }
    else
    {
        if (node->Left == NULL && node->Right == NULL)
        {
            node = NULL;
        }
        else if (!(node->data != 3) && (node->Left != ((void *)0))) {
            node->Left->Parent = node->Parent;
            node = node->Left;
} else if (node->Left == ((void *)0) && node->Right != ((void *)0)) {
            node->Right->Parent = node->Parent;
            node = node->Right;
} else {
            Node* deleteNode = node;
            Node* minNode = GetMinNode(node->Right, deleteNode);
            minNode->Parent = node->Parent;
            minNode->Left = deleteNode->Left;
    if (deleteNode->Left != ((void *)0)) {
                deleteNode->Left->Parent = minNode;
            }
            minNode->Right = deleteNode->Right;
    if (deleteNode->Right != ((void *)0)) {
                deleteNode->Right->Parent = minNode;
            }
            node = minNode;
            free(deleteNode);
        }
    }

    return node;
}



void Inorder(Node* node, int* result) {
    if (node == NULL) return;
    if (curIndex >= 11) return;

    Inorder(node->Left, result);

    printf("%d \n", node->data);

    if (node->Right != NULL) {
        printf("Right: %d\n", node->Right->data);
    }
    if (node->Left != NULL) {
        printf("Left: %d\n", node->Left->data);
    }


    result[curIndex] = node->data;
    curIndex++;
    Inorder(node->Right, result);
}

int* getInorder(Node* node) {
    int* result = (int*)malloc(sizeof(int) * 11);
    for(int i = 0; i < 11; i++) {
        result[i] = 0;
    }
    Inorder(node, result);
    return result;
}