#include<vector>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include"RUI.h"
#define max 100
using namespace std;
struct node
{
	char val;
	int height;
	node *lchild,*rchild;
};
//m=n=1
sequencetree BFS(node* root,int m,int n,int c[],char d[])
{
	sequencetree T;
	char str[max]="AVL";
	initialize(T,str);
	int num;
	queue<node*>q;
	q.push(root);
	c[m]=n;
	d[c[m]]=root->val;
	m=m+1;
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		if(now->lchild!=NULL)
		{
			q.push(now->lchild);
			c[m]=n+1;
			d[c[m]]=now->lchild->val;
			m=m+1;
			n=n+1;
		}
		if(now->rchild!=NULL)
		{
			q.push(now->rchild);
			c[m]=n+1;
			d[c[m]]=now->rchild->val;
			m=m+1;
			n=n+1;
		}	
	}
	for(num=1;num<=n;num++)
	{
		T.length[num-1]=c[num];
		T.data[T.length[num-1]]=d[c[num]];
		T.size++;
	}
	return T;
 } 
 
 
 int a=0;
 void BFS_tree(char val[],sequencetree A12,int z,char a1[],int a2[])
 {
 	if(A12.data[z]!=' ')
 	{
 		a2[a]=z;
    	a1[a2[a]]=val[a];
    //	printf("%d",T.length[a]);
    	a++;
	}
	else
	{
		return;
	}
 	
 	BFS_tree(val,A12,2*z,a1,a2);
 	BFS_tree(val,A12,2*z+1,a1,a2);
 }

