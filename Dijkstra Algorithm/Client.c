#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PES1UG19CS438_H.h"

void main(){
	int n,i=0;		//n-number of vertices
	FILE* fptr;
	fptr = fopen("adjacencylist.txt","r");
	fscanf(fptr,"%d",&n);
	fgetc(fptr);
	Node** adjacencyList = readInput(fptr,n);
	Dijkstra(n,n,adjacencyList);
	fclose(fptr);
}
