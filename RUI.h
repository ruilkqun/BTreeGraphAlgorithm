#include "STRUCT.h"
void initialize(sequencetree &T,char c[]);
sequencetree create(sequencetree &T);
void My_BFS(int row,int col,int level,char (*a)[max],int &n,int b[],int c[],int (*d)[max],int &k);
void  my_prin(sequencetree T);
sequencetree insertnode(sequencetree &T,int loc,char c);
void Algorithm(sequencetree &T,int num,int loc,int values,int z[]);
void inserttree(sequencetree &ROOT,int loc,sequencetree T);
void root(char x,sequencetree T);
void father(char x,sequencetree T);
void child(char x,sequencetree T);
void brother(char x,sequencetree T);
