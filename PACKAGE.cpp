#include<stdio.h>
#include "STRUCT.h"
#include "MATHEMATIC.h"
const int num=100;
int package()
{
	backpack list[num];
	int dp[num];
	int V,N;
	printf("Please input V and N:\n");
	while(scanf("%d%d",&V,&N)!=EOF)
	{
	    printf("Please input the volume and value of each item:\n");
		for(int k=1;k<=N;k++)
		{
			scanf("%d%d",&list[k].w,&list[k].v);
		}
		for(int k=0;k<=V;k++ )
        {
            dp[k]=0;
        }
        for(int k=1;k<=N;k++)
        {
            for(int j=V;j>=list[k].w;j--)
            {
                dp[j]=_max(dp[j],dp[j-list[k].w]+list[k].v);
            }
        }
        printf("In the case of volume no more than %d,the maximum value is %d",V,dp[V]);
	}
	return 0;
}
