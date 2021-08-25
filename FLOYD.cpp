#include<stdio.h>
const int max=100;
int floyd()
{
    int ans[max][max];
    int n,m;
    printf("Please input numbers of points and edges:\n");
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y;
        if(n==0&&m==0)
        {
            break;
        }
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=n;b++)
            {
                ans[a][b]=-1;
            }
            ans[a][a]=0;
        }
        printf("Please input two points on the edge and the weights:\n");
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ans[a][b]=ans[b][a]=c;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(ans[i][k]==-1||ans[k][j]==-1)
                    {
                        continue;
                    }
                    if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
                    {
                        ans[i][j]=ans[i][k]+ans[k][j];
                    }
                }
            }
        }
        do
        {
            printf("Please input two points:\n");
            scanf("%d%d",&x,&y);
            printf("The shortest distance between Point %d and point %d is %d\n",x,y,ans[x][y]);
        }while(x!=0&&y!=0);
    }
    return 0;
}
