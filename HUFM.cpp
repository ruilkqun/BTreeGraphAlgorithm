#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include "RUI.h"
#define max 100
using namespace std;




priority_queue<char,vector<char>,greater<char> >q;

char HUFM(sequencetree T)
{
	char result=0;
	char data[max];
	int i=0,n=T.size;
	int m=1;
	for(i=0;i<n;i++)
	{
		if((T.data[T.length[i]]-'a')>=0)
		{
			q.push(T.data[T.length[i]]-96);
		}
		else if((T.data[T.length[i]]-'A')>=0)
		{
			q.push(T.data[T.length[i]]-64);
		}
		else if((T.data[T.length[i]]-'1')>=0)
		{
			q.push(T.data[T.length[i]]-48);
		}
	}
	while(q.size()>1)
	{
		data[m]=q.top();
		q.pop();
		m=m+1;
		data[m]=q.top();
		q.pop();
		result=data[m]+data[m-1];
		m=m+1;
		q.push(result);
	}
	q.pop();
	return result;
}
