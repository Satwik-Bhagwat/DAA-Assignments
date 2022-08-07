#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"server.h"

void main(){
	int i,j,size,*a;
	FILE *f1,*f2;
	f1=fopen("execution_time.txt","a");
	f2=fopen("comparisons.txt","a");
	fprintf(f1,"\t\t\tSize and Execution time\n");
	fprintf(f2,"\t\t\tSize and Comparisons\n");
	srand(time(0));
	for(i=100000;i<=1000000;i=i+50000)
	{
		size=i;
		a=(int*)malloc(sizeof(int)*i);
		fprintf(f1,"%d elements\n",size);
		fprintf(f2,"%d elements\n",size);
		clock_t start,end;
		double total_time;
		
		for(j=0;j<i;j++)
			a[j]=rand();
		count=0;
		start = clock();
		quick_sort(a,0,size-1);
		end = clock();
		total_time = ((double)(end-start))/CLOCKS_PER_SEC;
		fprintf(f1,"\tquick sort : %lf\n",total_time);
		fprintf(f2,"\tquick sort : %lld\n",count);
	
		for(j=0;j<i;j++)
			a[j]=rand();
		count=0;
		start = clock();
		merge_sort(a,0,size-1);
		end = clock();
		total_time = ((double)(end-start))/CLOCKS_PER_SEC;
		fprintf(f1,"\tmerge sort : %lf\n",total_time);
		fprintf(f2,"\tmerge sort : %lld\n",count);
	
		for(j=0;j<i;j++)
			a[j]=rand();
		count=0;
		start = clock();
		bubble_sort(a,size);
		end = clock();
		total_time = ((double)(end-start))/CLOCKS_PER_SEC;
		fprintf(f1,"\tbubble sort : %lf\n",total_time);
		fprintf(f2,"\tbubble sort : %lld\n",count);
		
		for(j=0;j<i;j++)
			a[j]=rand();
		count=0;
		start = clock();
		selection_sort(a,size);
		end = clock();
		total_time = ((double)(end-start))/CLOCKS_PER_SEC;
		fprintf(f1,"\tselection sort : %lf\n",total_time);
		fprintf(f2,"\tselection sort : %lld\n",count);

		free(a);
	}
	fclose(f1);
	fclose(f2);
}
