#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int num=101;

int topological_sort()
{
    vector<int> EDGE[num];
    queue<int> Q;
    int indegree[num];
    int n,m;
    printf("Please input numbers of points and edges:\n");
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            indegree[i]=0;
            EDGE[i].clear();
        }
        printf("Please input edge:\n");
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            indegree[b]++;
            EDGE[a].push_back(b);
        }
        while(Q.empty()==false)
        {
            Q.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                Q.push(i);
            }
        }
        int cnt=0;
        while(Q.empty()==false)
        {
            int nowp=Q.front();
            Q.pop();
            cnt++;
            for(int i=0;i<EDGE[nowp].size();i++)
            {
                indegree[EDGE[nowp][i]]--;
                if(indegree[EDGE[nowp][i]]==0)
                {
                    Q.push(EDGE[nowp][i]);
                }
            }
        }
        if(cnt==n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
