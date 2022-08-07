#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long int count;//to count number of comparisons
void bubble_sort(int*,int);
void selection_sort(int*,int);
void merge_sort(int*,int,int);
void merge(int*,int,int,int);
void quick_sort(int*,int,int);
int partition(int*,int,int);
