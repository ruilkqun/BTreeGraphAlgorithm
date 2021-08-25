#include<math.h>
const int  max=100;
struct sequencetree
{
	char data[max];
	int length[max];
	int size;
};

struct edge
{
    int a,b;
    int cost;
    bool operator < (const edge &A) const
    {
        return cost<A.cost;
    }
};

struct Edge
{
    int a,b;
    double cost;
    bool operator < (const Edge &A) const
    {
        return cost<A.cost;
    }
};


struct point
{
    double x,y;
    double get_Distance(point A)
    {
        double temp=(x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);
        return sqrt(temp);
    }
};


struct E
{
    int next;
    int c;
};



struct update_E
{
    int next;
    int c;
    int cost;
};

struct backpack
{
	int w;
	int v;
};
