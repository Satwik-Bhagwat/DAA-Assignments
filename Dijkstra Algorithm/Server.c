#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "PES1UG19CS438_H.h"



Node** readInput(FILE* fptr,int n)
{
	char c;
	int k,i,src,dest,wt;
	Node** adjList;
	adjList=(Node**)malloc(n*sizeof(Node*));
	for(i=0;i<n;i++)
		*(adjList+i)=NULL;
	for(i=0;i<n;i++)
	{
		if(fgetc(fptr)==EOF)
			break;
		fseek(fptr,-1,SEEK_CUR);		//cursor will be ahead due to fgetc
		fscanf(fptr,"%d",&src);
		fgetc(fptr);
		while(fgetc(fptr)!='\n')
		{
			fseek(fptr,-1,SEEK_CUR);
			fscanf(fptr,"%d",&dest);
			fscanf(fptr,"%d",&wt);
			createAdjList(src-1,dest,wt,adjList);
		}
	}
	return adjList;
}

void createAdjList(int src,int dest,int wt,Node** adjList)
{
	Node *newNode,*temp;
	newNode=(Node*)malloc(sizeof(Node));
	newNode->vertex=dest;
	newNode->weight=wt;
	newNode->next=NULL;
	temp=*(adjList+src);
	if(temp==NULL)
		*(adjList+src)=newNode;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}
}

heapNode* createHeapNode(int dist,int vnum,int pred)		//to create and return new heap node
{
	heapNode* new = (heapNode*)malloc(sizeof(heapNode));
	new->distance = dist;
	new->vertexNum = vnum;
	new->pre = pred;
	return new;
}

heap* createHeap(int capacity)		//to create a new heap
{
	heap* newHeap = (heap*)malloc(sizeof(heap));
	newHeap->size = 0;
	newHeap->capacity = capacity;
	newHeap->array = (heapNode**)malloc(capacity*(sizeof(heapNode*)));
	return newHeap; 
}

void swapNode(heapNode** x,heapNode** y)
{
	heapNode* temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(heap* Heap,int index)
{
	int smallest,left,right;
	smallest = index;
	left = 2*index+1;
	right=2*index+2;
	
	if(left<Heap->size && (Heap->array[left])->distance < (Heap->array[smallest])->distance)
		smallest = left;
	if(right<Heap->size && (Heap->array[right])->distance < (Heap->array[smallest])->distance)
		smallest = right;
	
	if(smallest!=index)
	{
		heapNode* smallNode = Heap->array[smallest];
		heapNode* indexNode = Heap->array[index];
		Heap->array[smallest]=Heap->array[index];
		Heap->array[index]=smallNode;
		//swapNode(&smallNode,&indexNode);
		heapify(Heap,smallest);
	}
}

heapNode* getMinNode(heap* Heap)		//returns root or heap with min value
{
	if(Heap->size==0)
		return NULL;
	
	heapNode* root  = Heap->array[0];
	Heap->array[0] = Heap->array[Heap->size-1];
	Heap->array[Heap->size-1] = root;
	Heap->size=Heap->size-1;
	heapify(Heap,0);
	return root;
}

void heapUpdate(heap* Heap,int vertex,int pred,int newDist)	// updates distance
{
	int i=0;
	heapNode* temp;
	while((Heap->array[i])->vertexNum!=vertex)
		i++;
	(Heap->array[i])->distance = newDist;
	(Heap->array[i])->pre = pred;
	while( i>0 && ( ((Heap->array[i])->distance) < ((Heap->array[(i-1)/2])->distance) ) )
	{
		temp = Heap->array[i];
		Heap->array[i] = Heap->array[(i-1)/2];
		Heap->array[(i-1)/2] = temp;
		//swapNode(&Heap->array[i],&Heap->array[(i-1)/2]);
		i=(i-1)/2;
	}
}

bool isPresent(int vertex,heap* Heap)		// to check if node is present in heap
{
	int i=0;
	for(i=0;i<(Heap->size);i++)
	{
		if((Heap->array[i])->vertexNum == vertex)
			return true;
	}
	return false;
}

int getIndex(int vertex,int n,heap* Heap)		// get position of a vertex in the array heap
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if((Heap->array[i])->vertexNum == vertex)
			return i;
	}
	return -1;
}

void Dijkstra(int src,int n,Node** adjList)
{
	int dist[n];
	int i,j,currentVertex,neighbour,pos;	//pos-position of a vertex in heap array
	heapNode *srcVertex,*currentNode;
	Node *temp;
	heap* min_heap = createHeap(n);
	for(i=0;i<n;i++)
	{
		dist[i] = INT_MAX;
		min_heap->array[i] = createHeapNode(dist[i],i,0);
		min_heap->size++;
	}
	dist[src-1]=0;
	heapUpdate(min_heap,src-1,0,0);
	while(min_heap->size!=0)
	{
		currentNode = getMinNode(min_heap);
		currentVertex = currentNode->vertexNum;
		for(j=0;j<n;j++)
		{
			temp = *(adjList+j);
			while(temp!=NULL)
			{
				if(temp->vertex==(currentVertex+1))
				{
					neighbour = j;
					if(isPresent(neighbour,min_heap) && dist[currentVertex]!=INT_MAX &&
					   temp->weight+dist[currentVertex] < dist[neighbour])
					{
					   	dist[neighbour] = temp->weight+dist[currentVertex];
					   	heapUpdate(min_heap,neighbour,currentVertex+1,dist[neighbour]);
					}
				}
				temp=temp->next;
			}
		}
	}
	
	for(i=0;i<n-1;i++)			//to print output
	{
		printf("%d ",i+1);
		if(dist[i]==INT_MAX)
			printf("NO PATH\n");
		else
		{
			printf("%d ",i+1);
			pos = getIndex(i,n,min_heap);
			while((min_heap->array[pos])->pre!=0)
			{
				printf("%d ",(min_heap->array[pos])->pre);
				pos = getIndex(((min_heap->array[pos])->pre-1),n,min_heap);
			}
			printf("%d\n",dist[i]);
		}
		
	}
}
