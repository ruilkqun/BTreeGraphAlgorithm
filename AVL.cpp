#include<stdio.h>
struct node
{
	char val;
	int height;
	node *lchild,*rchild;
};

char Max(char a,char b)
{
	if(a>b)
    	return a;
	else
        return b;
}

node* new_Node(char val)
{
	node* Node=new node;
	Node->val=val;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;
}

int get_Height(node* root)
{
	if(root==NULL)
    	return 0;
    return root->height;
}

int get_BF(node* root)
{
	return get_Height(root->lchild)-get_Height(root->rchild);
}

void update_Height(node* &root)
{
	root->height=Max(get_Height(root->lchild),get_Height(root->rchild))+1;
}

void L(node* &root)
{
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update_Height(root);
	update_Height(temp);
	root=temp;
}

void R(node* &root)
{
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update_Height(root);
	update_Height(temp);
	root=temp;
}

void insert(node* &root,char val)
{
	if(root==NULL)
	{
		root=new_Node(val);
		return;
	}
	if(val<root->val)
	{
		insert(root->lchild,val);
		update_Height(root);
		if(get_BF(root)==2)
		{
			if(get_BF(root->lchild)==1)
			{
				R(root);
			}
			else if(get_BF(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		insert(root->rchild,val);
		update_Height(root);
		if(get_BF(root)==-2)
		{
			if(get_BF(root->rchild)==-1)
			{
				L(root);
			}
			else if(get_BF(root->rchild)==1)
			{
				R(root->lchild);
				L(root);
			}
		}
	}
}

node* Create_AVL(char data[],int n)
{
	node* root=NULL;
	for(int i=0;i<n;i++)
	{
		insert(root,data[i]);
	}
	return root;
}
