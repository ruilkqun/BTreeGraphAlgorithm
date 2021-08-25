#include<stdio.h>
#include<stack>
using namespace std;
const int num=200;

char str[num];
stack<int> op;
stack<double> in;
int mat[][5]=
   {
    	1,0,0,0,0,
    	1,0,0,0,0,
    	1,0,0,0,0,
    	1,1,1,0,0,
    	1,1,1,0,0,
    };


void getop(bool &o,int &n,int &i)
{
	if(i==0&&op.empty()==true)
	{
		o=true;
		n=0;
		return;
	}
	if(str[i]==0)
	{
		o=true;
		n=0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9')
	{
		o=false;
	}
	else
	{
		o=true;
		if(str[i]=='+')
		{
			n=1;
		}
		else if(str[i]=='-')
		{
			n=2;
		}
		else if(str[i]=='*')
		{
			n=3;
		}
		else if(str[i]=='/')
		{
			n=4;
		}
		i+=2;
		return;
	}
	n=0;
	for(;str[i]!=' '&&str[i]!=0;i++)
	{
		n*=10;
		n+=str[i]-'0';
	}
	if(str[i]==' ')
	{
		i++;
	}
	return;
}



int calculator()
{
	printf("Please input express:\n");
	getchar();
	while(gets(str))
	{
		if(str[0]=='0'&&str[1]==0)
		{
			break;
		}
		bool retop;
		int num;
		int id=0;
		while(!op.empty())
		{
			op.pop();
		}
		while(!in.empty())
		{
			in.pop();
		}
		while(true)
		{
			getop(retop,num,id);

			if(retop==false)
			{
				in.push((double)num);
			}
			else
			{
				double temp;
				if(op.empty()==true||mat[num][op.top()]==1)
				{
					op.push(num);
				}
				else
				{
					while(mat[num][op.top()]==0)
					{
						int ret=op.top();
						op.pop();
						double b=in.top();
						in.pop();
						double a=in.top();
						in.pop();
						if(ret==1)
						{
							temp=a+b;
						}
						else if(ret==2)
						{
							temp=a-b;
						}
						else if(ret==3)
						{
							temp=a*b;
						}
						else
						{
							temp=a/b;
						}
						in.push(temp);
					}
					op.push(num);
				}
			}
			if(op.size()==2&&op.top()==0)
			{
				break;
			}
		}
		printf("ans=%.2f\n",in.top());
	}
	return 0;
}
