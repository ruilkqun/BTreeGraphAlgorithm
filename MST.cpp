#include "STRUCT.h"

int findroot(int x,int TREE[])
{
    if(TREE[x]==-1)
    {
        return x;
    }
    else
    {
        int temp=findroot(TREE[x],TREE);
        TREE[x]=temp;
        return temp;
    }
}


