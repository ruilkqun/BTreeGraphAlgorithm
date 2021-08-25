#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
//#include<ctype.h>
#include<string.h>
#include "AVL.h"
#include "RUI.h"
#include "VISITED.h"
#include "HUFM.h"
#include "TRAVERSAL.h"
#include "FINDTREE.h"
#include "HEAP.h"
#include<algorithm>
using namespace std;
#include "MST.h"
#include "FLOYD.h"
#include "DIJKSTRA.h"
#include "TOPOLOGICAL_SORT.h"
#include "PARENTHESES_MATCH.h"
#include "CALCULATOR.h"
#include "THREAD.h"
#include "PACKAGE.h"
//#include<stack>
#include<graphics.h>
#include "TRAFFIC.h"
#include "STUDENT_ACHIEVEMENT.h"
#include "SCHEDULE.h"
#define max 100
int main()
{
	printf("====================================================================================================");
	printf("\t\n                                    ORIGINAL KERNEL                                         \t\n");
	printf("\n");
	printf("\t                                   ^                                                              ");
	printf("\t                                ^     ^                                                           ");
	printf("\t                             ^     ^     ^                                                        ");
	printf("\t                          ^     ^     ^     ^                                                     ");
	printf("\t                        ^    ^     ^     ^     ^                                                  ");
	printf("\t                     ^    ^     ^     ^      ^     ^                                              ");
	printf("\t                  ^     ^    ^     ^     ^      ^     ^                                           ");
	printf("\t               ^     ^    ^     ^     ^      ^     ^     ^                                        ");
	printf("\t            ^     ^     ^    ^     ^     ^      ^     ^     ^                                     ");
	printf("\t         ^     ^     ^    ^     ^     ^      ^     ^     ^     ^                                  ");
	printf("\t      ^     ^     ^     ^    ^     ^     ^      ^     ^     ^     ^                               ");
	printf("\t   ^     ^     ^     ^    ^     ^     ^      ^     ^     ^     ^     ^                            ");
	printf("\t^                           ----------------                            ^                         ");
	printf("\t                            ||            ||                                                      ");
	printf("\t                            ||            ||                                                      ");
	printf("\t                            ||            ||                                                      ");
	printf("\t                            ||            ||                                                      ");
	printf("\t                            ||            ||                                                      ");
	printf("\t ///////////////////////////||            ||//////////////////////////////                        ");
	printf("\t ---------------------------||            ||------------------------------                        ");
	printf("\t                            ||            ||                                                      ");
	printf("\t ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~                        ");
	printf("\t                            ||            ||                                                      ");
	printf("\t ///////////////////////////||            ||//////////////////////////////                        ");
	printf("\t                            ||============||                                                      ");
	char data[max];
	int i=0,flag=0,flag1=0;
	char x;
	int loc;
	char numbers;
	char c1[max]="First",c2[max]="Second",c3[max]="Third";
	sequencetree T1,T2,T3,A1,*A2,*A3,A4,A5,A6,A7,A8,A91,A9,A101,A11,A12;
	int A10;
	node* X;
	int num=0;
	int m=1,n=1;
	int c[max];
	char d[max];
	printf("\n");
	printf("====================================================================================================");
    printf("\t                                   INIT                                                         \t");
    printf("\n");
	initialize(T1,c1);
	initialize(T2,c2);
	initialize(T3,c3);
	printf("\n");
	printf("====================================================================================================");
    printf("\t                                   OPER                                                       \t\n");
	printf("1--------------------------------------create(&T)                                                 \n");
	printf("2----------------------------------insertnode(&T,loc,c)                                           \n");
	printf("3----------------------------------inserttree(&ROOT,loc,T)                                        \n");
	printf("4--------------------------------------root(x,T)                                                  \n");
	printf("5--------------------------------------father(x,T)                                                \n");
	printf("6--------------------------------------child(x,T)                                                 \n");
	printf("7--------------------------------------brother(x,T)                                               \n");
	printf("8--------------------------------------print(T)                                                   \n");
	printf("9----------------------------------T change to AVL(T)                                             \n");
	printf("10---------------------------------Calculate WPL of tree(T)                                       \n");
	printf("11---------------------------------Traversal of tree(T,i)                                         \n");
	printf("12---------------------------------Find Original Tree()                                           \n");
	printf("13-------------------------------------Heap Sort(T)                                               \n");
	printf("14---------------------------------------MST                                                      \n");
	printf("15-------------------------------------Kruskal(select point)                                      \n");
	printf("16------------------------Floyd(Shortest path between two points,FULL SOURCE)                     \n");
	printf("17----------------------Dijkstra(Shortest path between two points,Single SOURCE)                  \n");
	printf("18--------------update_Dijkstra(Shortest path and costs between two points,Single SOURCE)         \n");
    printf("19-----------------------Topological_sort(Judge DAG-directed acyclic graph)                       \n");
    printf("20------------------------------Parentheses Matching(Stack )                                      \n");
	printf("21------------------------------A Simple Calculator(Stack )                                       \n");
	printf("22---------------------------------------Hash1                                                    \n");
	printf("23---------------------------------------Hash2                                                    \n");
	printf("24--------------------------------------Echelon                                                   \n");
	printf("25----------------------------------Folding basket                                                \n");
	printf("26---------------------------------------Thread                                                   \n");
	printf("27------------------------------------0-1 Package                                                 \n");
	printf("28-----------------------------------Traffic System                                               \n");
	printf("29-----------------------Student Achievement management system                                    \n");
	printf("30-------------------------------------Schedule                                                   \n");
	printf("31---------------------------------------exit                                                     \n");
	printf("====================================================================================================");
	printf("\n");

	do
	{
		printf("Please input your select function(1-30):\n");
		scanf("%d",&i);
		if(i==1)
		{
			printf("Please input the label of create tree(1,2,3):\n");
			scanf("%d",&flag);
			if(flag==1)
	    		A1=create(T1);
			else if(flag==2)
				A1=create(T2);
			else if(flag==3)
				A1=create(T3);
		}
		else if(i==2)
		{
			printf("Please input the values of insert node:\n");
			scanf("%c",&x);
			scanf("%c",&numbers);
			printf("Please input the location of insert node:\n");
			scanf("%d",&loc);
			printf("Please input the label of insert tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
		    	A2=&T1;
			else if(flag==2)
				A2=&T2;
			else if(flag==3)
			    A2=&T3;
			insertnode(*A2,loc,numbers);
		}
		else if(i==3)
		{
			printf("Please input the label of root tree(1 or 2 or 3):\n");
			scanf("%c",&x);
			scanf("%d",&flag1);
			printf("Please input the location of insert node:\n");
			scanf("%d",&loc);
			printf("Please input the label of insert tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag1==1)
			    A3=&T1;
			else if(flag1==2)
			    A3=&T2;
			else if(flag1==3)
			    A3=&T3;
			if(flag==1)
		    	inserttree(*A3,loc,T1);
			else if(flag==2)
				inserttree(*A3,loc,T2);
			else if(flag==3)
			    inserttree(*A3,loc,T3);
		}
		else if(i==4)
		{
			printf("Please input the values of search node:\n");
			scanf("%c",&x);
			scanf("%c",&numbers);
			printf("Please input the label of search tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
		    	A4=T1;
			else if(flag==2)
				A4=T2;
			else if(flag==3)
			    A4=T3;
		}
		else if(i==5)
		{
			printf("Please input the values of search node:\n");
			scanf("%c",&x);
			scanf("%c",&numbers);
			printf("Please input the label of search tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
				A5=T1;
			else if(flag==2)
				A5=T2;
			else if(flag==3)
			    A5=T3;
		}
		else if(i==6)
		{
			printf("Please input the values of search node:\n");
			scanf("%c",&x);
			scanf("%c",&numbers);
			printf("Please input the label of search tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
				A6=T1;
			else if(flag==2)
				A6=T2;
			else if(flag==3)
			    A6=T3;
		}
		else if(i==7)
		{
			printf("Please input the values of search node:\n");
			scanf("%c",&x);
			scanf("%c",&numbers);
			printf("Please input the label of search tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
				A7=T1;
			else if(flag==2)
				A7=T2;
			else if(flag==3)
			    A7=T3;
		}
		else if(i==8)
		{
			printf("Please input the label of display tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
				A8=T1;
			else if(flag==2)
				A8=T2;
			else if(flag==3)
			    A8=T3;
		}
		else if(i==9)
		{
		  	printf("Please input the label of tree that converted to AVL(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
			{
				A91=T1;
	    	}
			else if(flag==2)
			{
				A91=T2;
			}
			else if(flag==3)
			{
				A91=T3;
			}
		    for(num=0;num<A91.size;num++)
		    {
		    	data[num]=A91.data[A91.length[num]];
		    }
		    X=Create_AVL(data,A91.size);
		    A9=BFS(X,m,n,c,d);
		}
        else if(i==10)
		{
		  	printf("Please input the label of tree that culcate WPL(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
			{
				A101=T1;
	    	}
			else if(flag==2)
			{
				A101=T2;
			}
			else if(flag==3)
			{
				A101=T3;
			}
			A10=HUFM(A101);
		}
		else if(i==11)
		{
			int f=1;
			int flag1;
			int count=0;
			int ans;
			char a1[max],a2[max],a3[max],a4[max];
		  	printf("Please input the label of tree that traversal(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
			{
				A11=T1;
	    	}
			else if(flag==2)
			{
				A11=T2;
			}
			else if(flag==3)
			{
				A11=T3;
			}
//			ans=A11.length[count];
//			for(count=0;count<A11.size-1;count++)
//			{
//				if(A11.length[count+1]>ans)
//				{
//					ans=A11.length[count+1];
//				}
//			}
			printf("Please input the type of traversal(1(pre) or 2(in) or 3(post))or 4(layer):\n");
			scanf("%d",&flag1);
			if(flag1==1)
			{
				printf("The Preorder Traversal Sequence of %d Tree is:",flag);
				preorder(A11,f,a1);
				for(int i=0;i<A11.size;i++)
				{
					printf(" %c ",a1[i]);
					if(i!=A11.size-1)
					{
						printf(" -> ");
					}
				}
	    	}
			else if(flag1==2)
			{
				printf("The Inorder Traversal Sequence of %d Tree is:",flag);
				inorder(A11,f,a2);
				for(int i=0;i<A11.size;i++)
				{
					printf(" %c ",a2[i]);
					if(i!=A11.size-1)
					{
						printf(" -> ");
					}
				}
			}
			else if(flag1==3)
			{
				printf("The Postorder Traversal Sequence of %d Tree is:",flag);
				postorder(A11,f,a3);
				for(int i=0;i<A11.size;i++)
				{
					printf(" %c ",a3[i]);
					if(i!=A11.size-1)
					{
						printf(" -> ");
					}
				}
			}
			else if(flag1==4)
			{
				printf("The Layerorder Traversal Sequence of %d Tree is:",flag);
				layerorder(A11,f,a4);
				for(int i=0;i<A11.size;i++)
				{
					printf(" %c ",a4[i]);
					if(i!=A11.size-1)
					{
						printf(" -> ");
					}
				}
			}
		}
		else if(i==12)
		{
			int f=1;
			int flag1;
			char a1[max],a2[max],a3[max],a4[max],b[max];
			//sequencetree T;
			int preL,preR,inL,inR,postL,postR,layerL,layerR;
			char val[max];
		  	printf("Please input the label of original tree(1 or 2 or 3):\n");
			scanf("%d",&flag);
			if(flag==1)
			{
				A12=T1;
	    	}
			else if(flag==2)
			{
				A12=T2;
			}
			else if(flag==3)
			{
				A12=T3;
			}
			sequencetree T;
 			char c[max]="Original";
 			initialize(T,c);
// 			T.length[0]=1;
// 			T.data[T.length[0]]='a';
// 			T.size++;
// 			my_prin(T);
			inorder(A12,f,b);
			printf("\n");
			printf("Already known, inorder of the tree is:");
			for(int l=0;l<A12.size;l++)
			{
				printf(" %c ",b[l]);
				if(l!=A12.size-1)
				{
					printf(" -> ");
				}
			}
			printf("\n\n");
			preL=inL=postL=layerL=0;
			preR=inR=postR=layerR=A12.size-1;
			printf("Please input the type that with inorder to find original tree(1(pre) or 2(post))or 3(layer):\n");
			scanf("%d",&flag1);
			if(flag1==1)
			{
				preorder(A12,f,a1);
                printf("Already known, preorder of the tree is:");
		    	for(int m=0;m<A12.size;m++)
		    	{
		    		printf(" %c ",a1[m]);
		    		if(m!=A12.size-1)
		    		{
		    			printf(" -> ");
		    		}
		        }
		        printf("\n\n");
				prefindtree(val,A12,a1,b,preL,preR,inL,inR);
				int z=1;
				char a2[max];
				int a3[max];
				printf("By Calculator ,Find The Original Tree is:\n");
				BFS_tree(val,A12,z,a2,a3);
				for(int l=0;l<A12.size;l++)
				{
					T.length[l]=a3[l];
					T.data[T.length[l]]=a2[a3[l]];
					T.size++;
				}
				my_prin(T);
	    	}
			else if(flag1==2)
			{
				postorder(A12,f,a1);
                printf("Already known, postorder of the tree is:");
		    	for(int m=0;m<A12.size;m++)
		    	{
		    		printf(" %c ",a1[m]);
		    		if(m!=A12.size-1)
		    		{
		    			printf(" -> ");
		    		}
		        }
		        printf("\n\n");
				postfindtree(val,A12,a1,b,postL,postR,inL,inR);
				int z=1;
				char a2[max];
				int a3[max];
				printf("By Calculator ,Find The Original Tree is:\n");
				BFS_tree(val,A12,z,a2,a3);
				for(int l=0;l<A12.size;l++)
				{
					T.length[l]=a3[l];
					T.data[T.length[l]]=a2[a3[l]];
					T.size++;
				}
				my_prin(T);
	    	}
			else if(flag1==3)
			{
				layerorder(A12,f,a1);
                printf("Already known, layerorder of the tree is:");
		    	for(int m=0;m<A12.size;m++)
		    	{
		    		printf(" %c ",a1[m]);
		    		if(m!=A12.size-1)
		    		{
		    			printf(" -> ");
		    		}
		        }
		        printf("\n\n");
				layerfindtree(val,A12,a1,b,layerL,layerR,inL,inR);
				int z=1;
				char a2[max];
				int a3[max];
				printf("By Calculator ,Find The Original Tree is:\n");
				BFS_tree(val,A12,z,a2,a3);
				for(int l=0;l<A12.size;l++)
				{
					T.length[l]=a3[l];
					T.data[T.length[l]]=a2[a3[l]];
					T.size++;
				}
				my_prin(T);
		    }
		}
		else if(i==13)
		{
			char heap[max];
			sequencetree T;
			char c[max]="Original Heap";
			initialize(T,c);
			printf("Please input original date(. stop):\n");
			char d='s';
			int m=0;
			getchar();
			scanf("%c ",&d);
			while(d!='.')
			{
				T.length[m]=m+1;
				T.data[T.length[m]]=d;
				T.size++;
				m=m+1;
				scanf("%c",&d);
			}
			printf("\n");
			printf("Original Heap is:\n");
			heap_sort(T);
		}
		else if(i==14)
        {
            int TREE[max];
            edge EDGE[max];
            int n;
            printf("Please the numbers of nodes:\n");
            while(scanf("%d",&n)!=EOF&&n!=0)
            {
                printf("Please input two points on the edge and the weights:\n");
                for(int k=1;k<=n*(n-1)/2;k++)
                {
                    scanf("%d%d%d",&EDGE[k].a,&EDGE[k].b,&EDGE[k].cost);
                }
                sort(EDGE+1,EDGE+1+n*(n-1)/2);
                for(int m=1;m<=n;m++)
                {
                    TREE[m]=-1;
                }
                int ans=0;
                for(int l=1;l<=n*(n-1)/2;l++)
                {
                    int a=findroot(EDGE[l].a,TREE);
                    int b=findroot(EDGE[l].b,TREE);
                    if(a!=b)
                    {
                        TREE[a]=b;
                        ans+=EDGE[l].cost;
                    }
                }
                printf("The shortest path is %d kilometres.\n",ans);
            }
        }
        else if(i==15)
        {
            int TREE[max];
            Edge EDGE[max];
            point LIST[max];
            int n;
            printf("Please the numbers of nodes:\n");
            while(scanf("%d",&n)!=EOF&&n!=0)
            {
                printf("Please input the location(x,y) of every points:\n");
                for(int q=1;q<=n;q++)
                {
                    scanf("%lf%lf",&LIST[q].x,&LIST[q].y);
                }
                int size=0;
                for(int w=1;w<=n;w++)
                {
                    for(int e=w+1;e<=n;e++)
                    {
                        EDGE[size].a=w;
                        EDGE[size].b=e;
                        EDGE[size].cost=LIST[w].get_Distance(LIST[e]);
                        size++;
                    }
                }
                sort(EDGE+1,EDGE+size);
                for(int m=1;m<=n;m++)
                {
                    TREE[m]=-1;
                }
                double ans=0;
                for(int l=0;l<size;l++)
                {
                    int a=findroot(EDGE[l].a,TREE);
                    int b=findroot(EDGE[l].b,TREE);
                    if(a!=b)
                    {
                        TREE[a]=b;
                        ans+=EDGE[l].cost;
                    }
                }
                printf("The shortest path is %.2lf kilometres.\n",ans);
            }
        }
        else if(i==16)
        {
            floyd();
        }
        else if(i==17)
        {
            dijkstra();
        }
        else if(i==18)
        {
            update_dijkstra();
        }
        else if(i==19)
        {
            topological_sort();
        }
        else if(i==20)
        {
        	parentheses_match();
		}
		else if(i==21)
		{
		    calculator();
		}
		else if(i==22)
		{
			int n;
			printf("Please input number:\n");
			while(scanf("%d",&n)!=EOF&&n!=0)
			{
				int Hash[max]={0};
				printf("Please input scores:\n");
				for(int k=1;k<=n;k++)
				{
					int x;
					scanf("%d",&x);
					Hash[x]++;
				}
				int x;
				printf("Please input search scores:\n");
				scanf("%d",&x);
				printf("ans=%d\n",Hash[x]);
			}
		}
		else if(i==23)
		{
		    #define OFFSET 50000
            int Hash[100001];
            int statistics[100001];
            int n,m;
            int v=0;
            printf("Please input two numbers:\n");
            while(scanf("%d%d",&n,&m)!=EOF)
            {
                for(int k=-50000;k<=50000;k++)
                {
                    Hash[k+OFFSET]=0;
                }
                printf("Please input dates:\n");
                for(int k=1;k<=n;k++)
                {
                    int x;
                    scanf("%d",&x);
                    Hash[x+OFFSET]=1;
                }
                for(int k=50000;k>=-50000;k--)
                {
                    if(Hash[k+OFFSET]==1)
                    {
                        //printf("%d",k);
                        statistics[v]=k;
                        v++;
                        m--;
                        if(m==0)
                        {
                            printf("After sorts ans=");
                            break;
                        }
                    }
                }
                for(int k=0;k<v;k++)
                {
                	printf("%d ",statistics[k]);
				}
            }
		}
        else if(i==24)
        {
        	int h;
        	printf("Please input height:\n");
        	while(scanf("%d",&h)!=EOF)
        	{
        		printf("ans=\n");
        		int maxline=h+(h-1)*2;
        		for(int k=1;k<=h;k++)
        		{
        			for(int j=1;j<=maxline;j++)
        			{
        				if(j<=maxline-h-(k-1)*2)
        				{
        					printf(" ");
						}
						else
						{
							printf("*");
						}
					}
					printf("\n");
				}
			}
		}
        else if(i==25)
        {
        	int out[max+max][max+max];
        	char a,b;
        	int n;
        	bool first=true;
        	printf("Please input triples:\n");
        	while(scanf("%d %c %c",&n,&a,&b)==3)
        	{
        		if(first==true)
        		{
        			first=false;
				}
				else
				{
					printf("\n");
				}
				for(int k=1,j=1;k<=n;k+=2,j++)
				{
					int x=n/2+1,y=x;
					x=x-j+1;
					y=y-j+1;
					char c=j%2==1?a:b;
					for(int l=1;l<=i;l++)
					{
						out[x+l-1][y]=c;
						out[x][y+l-1]=c;
						out[x+k-1][y+l-1]=c;
						out[x+l-1][y+k-1]=c;
					}
				}
				if(n!=1)
				{
					out[1][1]=' ';
					out[n][1]=' ';
					out[1][n]=' ';
					out[n][n]=' ';
				}
				for(int m=1;m<=n;m++)
				{
					for(int v=1;v<=n;v++)
					{
						printf("%c",out[m][v]);
					}
					printf("\n");
				}
			}
		}
		else if(i==26)
		{
			thread();
		}
		else if(i==27)
		{
			package();
		}
		else if(i==28)
		{
			traffic();
		}
		else if(i==29)
		{
			stu_achievement();
		}
		else if(i==30)
		{
			schedule();
		}

		switch(i)
		{
		case 1:
			my_prin(A1);
			break;
		case 2:
			my_prin(*A2);
			break;
		case 3:
			my_prin(*A3);
			break;
		case 4:
			root(numbers,A4);
			break;
		case 5:
			father(numbers,A5);
			break;
		case 6:
			child(numbers,A6);
			break;
		case 7:
			brother(numbers,A7);
			break;
		case 8:
			my_prin(A8);
			break;
		case 9:
			my_prin(A9);
			break;
		case 10:
			printf("\tThe tree of %d through converted to HUFM calculate is WPL=%d\n",flag,A10);
			break;
		case 11:
			printf("\n\n");
			break;
		case 12:
			printf("\n");
			break;
		case 13:
			printf("\n");
			break;
		case 14:
		    printf("\n");
			break;
        case 15:
		    printf("\n");
			break;
        case 16:
		    printf("\n");
			break;
		case 17:
		    printf("\n");
			break;
        case 18:
		    printf("\n");
			break;
        case 19:
		    printf("\n");
			break;
		case 20:
		    printf("\n");
			break;
		case 21:
		    printf("\n");
			break;
		case 22:
		    printf("\n");
			break;
		case 23:
		    printf("\n");
			break;
		case 24:
		    printf("\n");
			break;
		case 25:
		    printf("\n");
			break;
		case 26:
		    printf("\n");
			break;
        case 27:
		    printf("\n");
			break;
		case 28:
		    printf("\n");
		    break;
		case 29:
		    printf("\n");
		    break;
		case 30:
		    printf("\n");
		    break;
        case 31:
            break;
		default:
			printf("input error,please heavy lose!\n");
			break;
		}
	}while(i!=30);
	return 0;
}


