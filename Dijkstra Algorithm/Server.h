#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node Node;

struct Node{
	Node* next;
	int vertex;
	int weight;
};

typedef struct heapNode {
    int distance;
    int vertexNum;
    int pre;	//predecessor
} heapNode;

typedef struct heap{
	int size;
	int capacity;
	heapNode** array;
}heap;

Node** readInput(FILE*,int);
void createAdjList(int,int,int,Node**);
heapNode* createHeapNode(int,int,int);
heap* createHeap(int);
void swapNode(heapNode**,heapNode**);
void heapify(heap*,int);
heapNode* getMinNode(heap*);
void Dijkstra(int,int,Node**);
void heapUpdate(heap*,int,int,int);
bool isPresent(int,heap*);
int getIndex(int,int,heap*);
