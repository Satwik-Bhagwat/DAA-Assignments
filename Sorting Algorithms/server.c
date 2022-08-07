#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"server.h"

void bubble_sort(int* ar,int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(ar[j+1]<ar[j])
			{
				flag=1;
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
			count++;
		}
		if(flag==0)
			break;
	}
	
}

void selection_sort(int* ar,int n)
{
	int i,j,min_index,temp;
	for(i=0;i<n-1;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
		{
			if(ar[min_index]>ar[j])
				min_index=j;
			count++;
		}
		temp=ar[min_index];
		ar[min_index]=ar[i];
		ar[i]=temp;
	}
}

void quick_sort(int* ar,int l,int r)
{
	if(l<r)
	{
		int s = partition(ar,l,r);	//s-split position
		quick_sort(ar,l,s-1);
		quick_sort(ar,s+1,r);
	}
}

int partition(int* ar,int l,int r)
{
	int pivot = ar[r];
	int i = l-1,j,temp;
	for(j=l;j<=r-1;j++)
	{
		if(ar[j]<pivot)
		{
			i++;
			temp=ar[i];
			ar[i]=ar[j];
			ar[j]=temp;
		}
		count++;
	}
	temp=ar[i+1];
	ar[i+1]=ar[r];
	ar[r]=temp;
	return (i+1);
}

void merge_sort(int* ar,int l_index,int r_index)
{
	if(l_index>=r_index)
		return;
	int m_index=l_index + ((r_index - l_index)/2);
	merge_sort(ar,l_index,m_index);
	merge_sort(ar,m_index+1,r_index);
	merge(ar,l_index,m_index,r_index);
}

void merge(int* arr,int l_in,int m_in,int r_in)
{
	int n_first = m_in-l_in+1;	//l_in-left index , r_in-right index , m_in-middle index
	int n_second = r_in-m_in;	//n_second-number of elements in second
	int left[n_first],right[n_second];
	int i;
	
	for(i=0;i<n_first;i++)
		left[i]=arr[l_in+i];
	for(i=0;i<n_second;i++)
		right[i]=arr[m_in+1+i];
	int j=0,k=l_in;i=0;	//i-index for n_first ,j-index for n_second, k-index for array
	
	while(i<n_first && j<n_second)
	{
		if(left[i]<=right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
		count++;
	}
	
	while(i<n_first)
	{
		arr[k] = left[i];
		k++;
		i++;
	}
	while(j<n_second)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}
