#include "STRUCT.h"
#include<stdio.h>
#include<vector>
const int num=100;
using namespace std;
int update_dijkstra()
{
    vector<update_E> EDGE[num];
    bool mark[num];
    int dis[num];
    int cost[num];
    int n,m;
    int s,e;
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
        printf("Please input the distance and costs between two points on the edge :\n");
        while(m--)
        {
            int a,b,c,cost;
            scanf("%d%d%d%d",&a,&b,&c,&cost);
            update_E temp;
            temp.c=c;
            temp.cost=cost;
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
        printf("Please input start and end point:\n");
        scanf("%d%d",&s,&e);
        dis[s]=0;
        mark[s]=true;
        int newp=s;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<EDGE[newp].size();j++)
            {
                int t;
                int c;
                int co;
                t=EDGE[newp][j].next;
                c=EDGE[newp][j].c;
                co=EDGE[newp][j].cost;
                if(mark[t]==true)
                {
                    continue;
                }
                if(dis[t]==-1||dis[t]>dis[newp]+c||dis[t]==dis[newp]+c&&cost[t]>cost[newp]+co)
                {
                    dis[t]=dis[newp]+c;
                    cost[t]=cost[newp]+co;
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
        printf("The shortest distance and costs between Point %d and point %d is %d kilometres and %d yuan\n",s,e,dis[e],cost[e]);
    }
    return 0;
}

