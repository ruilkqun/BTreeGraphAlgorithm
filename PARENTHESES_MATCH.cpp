#include<stdio.h>
#include<stack>
using namespace std;
const int num=101;


int parentheses_match()
{
	stack<int> S;

    char str[num];
    char ans[num];
	printf("Please input original string:\n");
	while(scanf("%s",str)!=EOF)
	{
		int i;
		for(i=0;str[i]!=0;i++)
		{
			if(str[i]=='(')
			{
				S.push(i);
				ans[i]=' ';
			}
			else if(str[i]==')')
			{
				if(S.empty()==false)
				{
					S.pop();
					ans[i]=' ';
				}
				else
				{
					ans[i]='?';
				}
			}
			else
			{
				ans[i]=' ';
			}
		}
		while(!S.empty())
		{
			ans[S.top()]='$';
			S.pop();
		}
		ans[i]=0;
		printf("Original string is:\n");
		puts(str);
		printf("New string is:\n");
		puts(ans);
	}
	return 0;
}
