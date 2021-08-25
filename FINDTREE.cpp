 #include<stdio.h>
 #include "RUI.h"
 int count=0,n=0,m=0;
 void prefindtree(char val[],sequencetree A12,char a[],char b[],int preL,int preR,int inL,int inR)
 { 
 	int k;
 	int num;
   	if(preL>preR)
	{
   	  return;
    }
	//val[A12.length[count]]=a[preL];
	//count=count+1;
	val[count]=a[preL];
	count=count+1;
	for(k=inL;k<=inR;k++)
	{
	 if(b[k]==a[preL])
	 {
	   	break;
	 }
	}
	num=k-inL;
	prefindtree(val,A12,a,b,preL+1,preL+num,inL,k-1);
	prefindtree(val,A12,a,b,preL+num+1,preR,k+1,inR);
 } 
 
 
 
 void postfindtree(char val[],sequencetree A12,char a[],char b[],int postL,int postR,int inL,int inR)
 { 
 	int k;
 	int num;
   	if(postL>postR)
	{
   	  return;
    }
	val[n]=a[postR];
	n=n+1;
	for(k=inL;k<=inR;k++)
	{
	 if(b[k]==a[postR])
	 {
	   	break;
	 }
	}
	num=k-inL;
	postfindtree(val,A12,a,b,postL,postL+num-1,inL,k-1);
	postfindtree(val,A12,a,b,postL+num,postR-1,k+1,inR);
 }
 
 
 
 void layerfindtree(char val[],sequencetree A12,char a[],char b[],int layerL,int layerR,int inL,int inR)
 { 
 	int k;
 	int num;
   	if(layerL>layerR)
	{
   	  return;
    }
	//val[A12.length[count]]=a[preL];
	//count=count+1;
	val[m]=a[layerL];
	m=m+1;
	for(k=inL;k<=inR;k++)
	{
	 if(b[k]==a[layerL])
	 {
	   	break;
	 }
	}
	num=k-inL;
	layerfindtree(val,A12,a,b,layerL+1,layerL+num,inL,k-1);
	layerfindtree(val,A12,a,b,layerL+num+1,layerR,k+1,inR);
 } 
  
