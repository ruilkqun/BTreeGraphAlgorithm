#include<stdio.h>
#include<queue>
#include "STRUCT.h"
using namespace std;

//char x=219;
int count1=0,count2=0,count3=0,count4=0;
void preorder(sequencetree T,int i,char a[])
{
	if(T.data[i]==' ')
	{
		return;
	}
	a[count1]=T.data[i];
//	printf(" %c",T.data[i]);
	count1++;
//	if(count1!=T.size)
//	{
//		printf(" -> ");
//	}
	preorder(T,i*2,a);
	preorder(T,i*2+1,a);
}


void inorder(sequencetree T,int i,char a[])
{
	if(T.data[i]==' ')
	{
		return;
	}
	inorder(T,i*2,a);
	a[count2]=T.data[i];
//	printf("%c",T.data[i]);
	count2++;
//	if(count2!=T.size)
//	{
//		printf(" -> ");
//	}
	inorder(T,i*2+1,a);
}


void postorder(sequencetree T,int i,char a[])
{
	if(T.data[i]==' ')
	{
		return;
	}
	postorder(T,i*2,a);
	postorder(T,i*2+1,a);
	a[count3]=T.data[i];
//	printf("%c",T.data[i]);
	count3++;
//	if(count3!=T.size)
//	{
//		printf(" -> ");
//	}
}

void layerorder(sequencetree T,int i,char a[])
{
	queue<char> q;
	q.push(T.data[i]);
	while(!q.empty())
	{
		char now=q.front();
		q.pop();
		a[count4]=now;
//		printf("%c",now);
    	count4++;
//    	if(count4!=T.size)
//    	{
//    		printf(" -> ");
//    	}
    	if(T.data[i*2]!=' ')
    	{
    		q.push(T.data[i*2]);
		}
		if(T.data[i*2+1]!=' ')
    	{
    		q.push(T.data[i*2+1]);
		}
		i=i+1;
	}
} 
