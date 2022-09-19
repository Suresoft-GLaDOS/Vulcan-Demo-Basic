//
// Created by sure on 2022-09-15.
//

#ifndef VULCAN_DEMO_BASIC_HUFFMAN_H
#define VULCAN_DEMO_BASIC_HUFFMAN_H

#endif //VULCAN_DEMO_BASIC_HUFFMAN_H

struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    unsigned freq;

    // Left and right child of this node
    struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of
// min-heap (or Huffman tree) nodes
struct MinHeap {

    // Current size of min heap
    unsigned size;

    // capacity of min heap
    unsigned capacity;

    // Array of minheap node pointers
    struct MinHeapNode** array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct MinHeapNode* newNode(char data, unsigned freq);

// A utility function to create
// a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity);

// A utility function to
// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b);

// The standard minHeapify function.
void minHeapify(struct MinHeap* minHeap, int idx);

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap);

// A standard function to extract
// minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap);

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode);

// A standard function to build min heap
void buildMinHeap(struct MinHeap* minHeap);

// A utility function to print an array of size n
void printArr(int arr[], int n);

// Utility function to check if this node is leaf
int isLeaf(struct MinHeapNode* root);

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct MinHeap* createAndBuildMinHeap(char data[],
                                      int freq[], int size);

// The main function that builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[],
                                     int freq[], int size);

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct MinHeapNode* root, int arr[],
                int top, char* result);

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
struct MinHeapNode* HuffmanCodes(char data[], int freq[], int size);

void Inorder(struct MinHeapNode* node, char* result);

char* getInorder(struct MinHeapNode* node);