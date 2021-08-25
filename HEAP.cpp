#include "MATHEMATIC.h"
//#include "STRUCT.h"
#include "RUI.h"
#include<stdio.h>
void downadj(int low,int high,char heap[])
{
   int i=low;
   int j=i*2;
   while(j<=high)
   {
   	if(j+1<=high&&heap[j+1]>heap[j])
   	{
   	   j=j+1;
	}
	if(heap[j]>heap[i])
	{
		swap(heap[j],heap[i]);
		i=j;
		j=j*2;
	}
	else
	{
		break;
	}
   }
}

void create_heap(sequencetree T,char heap[])
{
	int n;
	n=T.size;
	for(int i=n/2;i>=1;i--)
	{
		downadj(i,n,heap);
	}
}


void upadj(int low,int high,char heap[])
{
	int i=high;
	int j=i/2;
	while(j>=low)
	{
		if(heap[j]<heap[i])
		{
			swap(heap[j],heap[i]);
			i=j;
			j=i/2;
		}
		else
		{
			break;
		}
	}
}

void insert(sequencetree T,char x,char heap[])
{
	int n;
	n=T.size;
	heap[++n]=x;
	upadj(1,n,heap);
}


void heap_sort(sequencetree T)
{
	char heap[max];
	int n=T.size;
	for(int k=0;k<n;k++)
	{
		heap[k+1]=T.data[T.length[k]];
	}
	create_heap(T,heap);
	for(int z=1;z<=T.size;z++)
	{
		T.data[z]=heap[z];
	}
	my_prin(T);
	for(int i=n;i>1;i--)
	{
		swap(heap[i],heap[1]);
		downadj(1,i-1,heap);
	}
	for(int y=1;y<=T.size;y++)
	{
		T.data[y]=heap[y];
	}
	printf("Sorted Heap is:\n");
	my_prin(T);
}
