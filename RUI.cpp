#include<stdio.h>
#include<math.h>
#include<stdio.h>
#include "STRUCT.h"
void initialize(sequencetree &T,char c[])
{
	int i;
	T.size=0;
	for(i=0;i<max;i++)
	{
		T.data[i]=' ';
		T.length[i]=0;
	}
	printf("\t                 The tree of %s has been initialized!\t\n",c);
}

sequencetree create(sequencetree &T)
{
	int i,n;
	int y;
	char x;
	printf("Please input the number of binary tree nodes:\n");
	scanf("%d",&n);
   	printf("Please input the location of each node and the value of each element:\n");
   	for(i=0;i<n;i++)
	{
	   	scanf("%d,%c",&y,&x);
	   	T.data[y]=x;
	   	T.length[i]=y;
	   	T.size++;
	}
	return T;
}




void My_BFS(int row,int col,int level,char (*a)[max],int &n,int b[],int c[],int (*d)[max],int &k)
{
	int l=0,m=0;
	int s=0;
	int num;
	for(l=0;l<level;l++)
	{
		num=(col+1)/pow(2.0,l+1);
		s=1;
		for(m=0;m<pow(2.0,l);m++)
		{
			b[k]=n;
			c[k]=num*s;;
			d[b[k]][c[k]]=k;
			if(n!=row-1)
			{
				a[n+1][c[k]-1]=47;
				a[n+1][c[k]+1]=92;
			}
			k=k+1;
			s=s+2;
		}
		n=n+2;
	}
}

void  my_prin(sequencetree T)
{
	char a[max][max];
	int b[max];
	int c[max];
	int d[max][max];
	int total=T.size;
	int level=(int)(log10((double)T.length[total-1])/log10(2.0))+1;
	int row=level+level-1;
	int col=79;
	int i=0,j=0;
	int n=0;
	int k=0;

	int num1=0,num2=0;
	int q=0;
	int cou=0;
	int mul;
	char ch=219;
	for(i=0;i<=row;i++)
	{
		for(j=0;j<=col+3;j++)
		{
			a[i][j]=219;
		}
	}
	My_BFS(row,col,level,a,n,b,c,d,k);
	for(i=0;i<T.size;i++)
	{
		for(j=0;j<pow(2.0,level)-1;j++)
		{
			if(T.length[i]==d[b[j]][c[j]]+1)
			{
				a[b[j]][c[j]]=T.data[T.length[i]];
			}
		}
	}
	for(i=0;i<level;i++)
	{
		q=1;
		num1=(col+1)/pow(2.0,i+1);
		for(j=0;j<pow(2.0,i);j++)
		{
			num2=(col+1)/pow(2.0,i+2);
			mul=num1*q;
		//	printf("%c",toascii(219));
			if(a[cou][mul]==ch)
		    {
			   	a[cou+1][mul-1]=219;
			   	a[cou+1][mul+1]=219;
			}
			else
			{
				if(a[cou+2][mul-num2]==ch)
				{
					a[cou+1][mul-1]=219;
				}
				if(a[cou+2][mul+num2]==ch)
				{
					a[cou+1][mul+1]=219;
				}
			}
			q=q+2;
		}
		cou=cou+2;;
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<=col+3;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//向一棵树中插入节点
sequencetree insertnode(sequencetree &T,int loc,char c)
{
	int i=0,n;
    n=T.size;
	while(T.length[i]!=loc&&i<n)
	{
		i++;
	}
	if(i!=n)
		printf("The location has existed!\n");
	else
	{
		T.length[T.size]=loc;
		T.data[T.length[T.size]]=c;
		T.size++;
	}
	return T;
}


//先序遍历算法
void Algorithm(sequencetree &T,int num,int loc,int values,int z[])
{
	int i=0;
	int x=0;
	int y=0;
	if(values!=0)
	{
	       for(i=0;i<T.size;i++)
	       {
	     	  if(z[i]==num*2)
	    	  {
	    	  	x=z[i];
	   	    	T.length[i]=loc*2;
	    	  }
	       }
	      for(i=0;i<T.size;i++)
	      {
	    	  if(z[i]==num*2+1)
	    	  {
	    	  	y=z[i];
	       		T.length[i]=loc*2+1;
	    	  }
	      }
	}
	else return;
	Algorithm(T,num*2,loc*2,x,z);
	Algorithm(T,num*2+1,loc*2+1,y,z);
 }

//向一棵树中插入另一棵树
void inserttree(sequencetree &ROOT,int loc,sequencetree T)
{
	int i=0,j=0;
	char d[max];
	int z[max];
	for(j=0;j<max;j++)
	{
		z[j]=0;
	 }
	while(ROOT.length[i]!=loc&&i<ROOT.size)
	{
		i++;
	}
	if(i!=ROOT.size)
		printf("The location has existed!\n");
	else
	{
		for(i=0;i<T.size;i++)
		{
			d[i]=T.data[T.length[i]];
		}
		for(i=0;i<T.size;i++)
	    {
	    	z[i]=T.length[i];
	    }
		Algorithm(T,T.length[0],loc,T.length[0],z);
		T.length[0]=loc;
		for(i=0;i<T.size;i++)
		{
			ROOT.length[ROOT.size]=T.length[i];
			ROOT.data[ROOT.length[ROOT.size]]=d[i];
    		ROOT.size++;
		}
	}
}


void root(char x,sequencetree T)
{
	int i=0,n;
    n=T.size;
	while(T.data[T.length[i]]!=x&&i<n)
	{
		i++;
	}
	if(i==n)
		printf("The node does't in the tree!\n");
	else
		printf("The root of this tree is %c\n",T.data[T.length[0]]);
}


void father(char x,sequencetree T)
{
	int i=0,n;
	while(T.data[T.length[i]]!=x&&i<T.size)
	{
		i++;
	}
	if(i==T.size)
		printf("The node doesn't' in the tree!\n");
	else
	{
		for(i=0;i<T.size;i++)
			if(T.data[T.length[i]]==x)
    		printf("In this tree,the node's father is %c\n",T.data[(int)(T.length[i]/2)]);
	}
}


void child(char x,sequencetree T)
{

	int i=0,n;
	n=T.size;
	while(T.data[T.length[i]]!=x&&i<n)
	{
		i++;
	}
	if(i==n)
		printf("The node doesn't' in the tree!\n");
	else
	{
		for(i=0;i<n;i++)
			if(T.data[T.length[i]]==x)
			{
				if(T.data[(int)(T.length[i]*2)]!=' ')
            		printf("In the tree,left child of this node is %c\n",T.data[T.length[i]*2]);
				if(T.data[T.length[i]*2+1]!=' ')
					printf("In the tree,right child of this node is %c\n",T.data[T.length[i]*2+1]);
			}
	}
}


void brother(char x,sequencetree T)
{
	int i=0,n;
	n=T.size;
	while(T.data[T.length[i]]!=x&&i<n)
	{
		i++;
	}
	if(i==n)
		printf("The node doesn't' in the tree!\n");
	else
	{
	    	for(i=0;i<n;i++)
		    	if(T.data[T.length[i]]==x)
				{
					if(T.length[i]%2==0)
					{
						if(T.data[T.length[i]-1]!=' ')
							printf("In the tree,the left brothers of this node is %c\n",T.data[T.length[i]-1]);
						else
							printf("In the tree,no left brothers of this node!\n");
					}
					else
					{
						if(T.data[T.length[i]+1]!=' ')
							printf("In the tree,the right brothers of this node is %c\n",T.data[T.length[i]+1]);
						else
							printf("In the tree,no right brothers of this node!\n");
					}
				}
	}
}



