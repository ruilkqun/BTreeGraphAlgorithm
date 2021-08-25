#include "STRUCT.h"
#include<stdio.h>
#include<vector>
const int num=100;
using namespace std;
int dijkstra()
{
    vector<E> EDGE[num];
    bool mark[num];
    int dis[num];
    int n,m;
    printf("Please input numbers of points and edges:\n");
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i=0;i<=n;i++)
        {
            EDGE[i].clear();
        }
        printf("Please input two points on the edge and the weights:\n");
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            E temp;
            temp.c=c;
            temp.next=b;
            EDGE[a].push_back(temp);
            temp.next=a;
            EDGE[b].push_back(temp);
        }
        for(int i=1;i<=n;i++)
        {
            dis[i]=-1;
            mark[i]=false;
        }
        dis[1]=0;
        mark[1]=true;
        int newp=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<EDGE[newp].size();j++)
            {
                int t;
                int c;
                t=EDGE[newp][j].next;
                c=EDGE[newp][j].c;
                if(mark[t]==true)
                {
                    continue;
                }
                if(dis[t]==-1||dis[t]>dis[newp]+c)
                {
                    dis[t]=dis[newp]+c;
                }
            }
            int min=num*num;
            for(int j=1;j<=n;j++)
            {
                if(mark[j]==true)
                {
                    continue;
                }
                if(dis[j]==-1)
                {
                    continue;
                }
                if(dis[j]<min)
                {
                    min=dis[j];
                    newp=j;
                }
            }
            mark[newp]=true;
        }
        printf("The shortest distance between Point 1 and point n is %d",dis[n]);
    }
    return 0;
}
