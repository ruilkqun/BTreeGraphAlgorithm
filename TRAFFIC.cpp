#include <stdio.h> 
#include <string.h> 
#define ERR 0 
#define OK 1 

#define Dij_max 33 
#define  vertex_max 31 
#define  string_max 10            
#define  traffic_max 10 

const char cityfile[] ="C:\\Users\\lvyeq\\Desktop\\Kernel\\city.txt"; 
const char trainfile[] ="C:\\Users\\lvyeq\\Desktop\\Kernel\\train.txt"; 
const char flightfile[] ="C:\\Users\\lvyeq\\Desktop\\Kernel\\flight.txt"; 
typedef short int citytype; 
typedef struct trafficnode 
{ 
   char name[string_max];        //班次 
   int starttime,stoptime;       //起止时间 
   int endcity;                  //该有向边指向的顶点在数组中的位置，即该城市编号 
   int cost;                     //票价 
} trafficnodedat; 
typedef struct vnode 
{ 
   citytype city; 
   int trainnum,flightnum;                 //标记下面Train数组和Flight数组里元素个数 
   trafficnodedat train[traffic_max];      //数组成员为结构体，记录到达该城市 
   trafficnodedat flight[traffic_max];     //起止时间、票价和班次
   int cost;                               //遍历时到达该城市的耗费（时间或者费用） 
} vnodedat; 
typedef struct pnode 
{ 
   int city; 
   int trano; 
} pnodedat; 

vnodedat  adjlist[vertex_max];                 //System Info 
char cityname[vertex_max][string_max];         //城市名，采用第一下标为该城市在本程序中的编号 
int citynum;                                   //城市数目 

pnodedat path[vertex_max];                     //存储临时最小时间路径 
pnodedat minpath[vertex_max];                  //存储搜索到当前的最小时间路径 

int mintime,starttime; 
int curpath;
int showmenu1()
{
     printf("\t\t******************************************************\n");
	 printf("\t\t*                                                    *\n");
	 printf("\t\t*   WELCOME TO THE NATIONAL TRAFFIC QUERY SYSTEM     *\n");
	 printf("\t\t* PRODUCER:Lu Rui,Hong Xun,Hu Cheng zhi(IOT Project) *\n");
	 printf("\t\t*        TIME:2014.11.26--2014.12.6                  *\n");
     printf("\t\t*                                                    *\n");
     printf("\t\t******************************************************\n"); 
     return 1;
}
int showmenu2() 
{ 
     printf("\n************MENU************\n"); 
     printf("1: ADD CITY\n2: DELETE CITY\n3:ADD TRAFFIC ROUTES\n4: DELETE TRAFFIC ROUTES\n5: MINIMUM COST ROUTING\n6: QUERY THE FASTEST ROUTE\n0: EXIT"); 
     printf("\n****************************\n"); 
     printf("\nType In Your Command:"); 
     return 1; 
}
int seekcity (char *name) 
{ 
  int i; 
  for (i=0;i<citynum;i++) 
  { 
    if (strcmp(name,cityname[i])==0) 
	{ 
      return i; 
	} 
  } 
  return -1; 
}
int savesysinfo() 
{ 
    FILE *fp;
    int i,j,total; 
    fp=fopen(cityfile,"w"); 
    fprintf(fp,"%d\n",citynum); 
    for (i=0;i<citynum;i++) 
	 { 
       fprintf(fp,"%s\n",cityname[i]); 
	 } 
     fclose(fp);total=0; 
     fp=fopen(trainfile,"w"); 
     for (i=0;i<citynum;i++) 
	 { 
       total+=adjlist[i].trainnum; 
	 } 
     fprintf(fp,"%d\n",total); 
     for (i=0;i<citynum;i++) 
	 { 
       for (j=0;j<adjlist[i].trainnum;j++) 
	   { 
          fprintf(fp,"%s %s %s ", adjlist[i].train[j].name, cityname[i], 
          cityname[adjlist[i].train[j].endcity]); 
          fprintf(fp,"%2d:%2d %2d:%2d %d\n", adjlist[i].train[j].starttime/60, 
          adjlist[i].train[j].starttime%60, 
          adjlist[i].train[j].stoptime/60, 
          adjlist[i].train[j].stoptime%60, 
          adjlist[i].train[j].cost); 
	   } 
	 } 
     fclose(fp);total=0; 
     fp=fopen(flightfile,"w"); 
     for (i=0;i<citynum;i++) 
	 { 
       total+=adjlist[i].flightnum; 
	 } 
     fprintf(fp,"%d\n",total); 
     for (i=0;i<citynum;i++) 
	 { 
       for (j=0;j<adjlist[i].flightnum;j++) 
	   { 
          fprintf(fp,"%s %s %s ", adjlist[i].flight[j].name, cityname[i], 
          cityname[adjlist[i].flight[j].endcity]); 
          fprintf(fp,"%2d:%2d %2d:%2d %d\n", adjlist[i].flight[j].starttime/60, 
          adjlist[i].flight[j].starttime%60, 
          adjlist[i].flight[j].stoptime/60, 
          adjlist[i].flight[j].stoptime%60,
          adjlist[i].flight[j].cost); 
	   } 
	 } 
     fclose(fp);return 1; 
}
int insertcity (char *name) 
{ 
          strcpy(cityname[citynum],name); 
          adjlist[citynum].city=citynum; 
          adjlist[citynum].flightnum=0; 
          adjlist[citynum].trainnum=0; 
          citynum++; 
          return 1; 
}

int delcity (char *name) 
{ 
    int city,i,j; 
    city=seekcity(name); 
    for (i=city;i<citynum-1;i++) 
	{ 
         strcpy(cityname[i],cityname[i+1]); 
         adjlist[i].flightnum=adjlist[i+1].flightnum; 
         adjlist[i].trainnum=adjlist[i+1].trainnum; 
         for (j=0;j<adjlist[i].flightnum;j++) 
		 { 
            adjlist[i].flight[j].cost=adjlist[i+1].flight[j].cost; 
            adjlist[i].flight[j].endcity=adjlist[i+1].flight[j].endcity; 
            strcpy(adjlist[i].flight[j].name,adjlist[i+1].flight[j].name); 
            adjlist[i].flight[j].starttime=adjlist[i+1].flight[j].starttime; 
            adjlist[i].flight[j].stoptime=adjlist[i+1].flight[j].stoptime; 
		 } 
	} 
    citynum--; 
    return 1; 
}
int inserttrain (char *train,char *startcity,char *endcity,int starttime,int endtime,int cost) 
{ 
        int i,j; 
        i=seekcity(startcity); 
        j=seekcity(endcity); 
        adjlist[i].train[adjlist[i].trainnum].cost=cost; 
        adjlist[i].train[adjlist[i].trainnum].endcity=j; 
        adjlist[i].train[adjlist[i].trainnum].starttime=starttime; 
        adjlist[i].train[adjlist[i].trainnum].stoptime=endtime; 
        strcpy(adjlist[i].train[adjlist[i].trainnum].name,train); 
        adjlist[i].trainnum++; 
        return 1; 
}
int insertflight(char *flight,char *startcity,char *endcity,int starttime,int endtime,int cost) 
{ 
        int i,j; 
        i=seekcity(startcity); 
        j=seekcity(endcity); 
        adjlist[i].flight[adjlist[i].flightnum].cost=cost; 
        adjlist[i].flight[adjlist[i].flightnum].endcity=j; 
        adjlist[i].flight[adjlist[i].flightnum].starttime=starttime; 
        adjlist[i].flight[adjlist[i].flightnum].stoptime=endtime; 
        strcpy(adjlist[i].flight[adjlist[i].flightnum].name,flight); 
        adjlist[i].flightnum++; 
        return 1; 
}
int delpath (char *name) 
{ 
   int i,j,flag=0; 
   for (i=0;i<citynum;i++) 
   { 
    for (j=0;j<adjlist[i].flightnum;j++) 
    if (strcmp(adjlist[i].flight[j].name,name)==0) 
	{ 
        flag=1;
		 break; 
	} 
    if (flag) 
	{ 
      for (;j<adjlist[i].flightnum-1;j++) 
	  { 
         adjlist[i].flight[j].cost=adjlist[i].flight[j+1].cost; 
         adjlist[i].flight[j].endcity=adjlist[i].flight[j+1].endcity; 
         strcpy(adjlist[i].flight[j].name,adjlist[i].flight[j+1].name); 
         adjlist[i].flight[j].stoptime=adjlist[i].flight[j+1].stoptime; 
	  } 
    adjlist[i].flightnum--;
	break; 
	} 
    for (j=0;j<adjlist[i].trainnum;j++) 
    if (strcmp(adjlist[i].train[j].name,name)==0) 
	{ 
        flag=1;
        break; 
	} 
    if (flag) 
	{ 
      for (;j<adjlist[i].trainnum-1;j++) 
	  { 
         adjlist[i].train[j].cost=adjlist[i].train[j+1].cost; 
         adjlist[i].train[j].endcity=adjlist[i].train[j+1].endcity; 
         strcpy(adjlist[i].train[j].name,adjlist[i].train[j+1].name); 
         adjlist[i].train[j].starttime=adjlist[i].train[j+1].starttime; 
         adjlist[i].train[j].stoptime=adjlist[i].train[j+1].stoptime; 
	  } 
      adjlist[i].trainnum--;
      break; 
	} 
   } 
   return 1; 
}
void Dijkstra_output(int matx[Dij_max][Dij_max],int precity[Dij_max],int p_end,int traveltype) 
{ 
   int track[Dij_max]; 
   int i=0,j,k,min,tmp,end,cost=0; 
   int startH, startM, endH, endM;      //定义四个变量:startH 出发的小时，startM 出发的分钟， endH 到达的小时， endM 到达的分钟
          
   j=p_end;
   track[i++]=j; 
   while (precity[j]>=0) 
   { 
     cost+=matx[precity[j]][j]; 
     track[i++]=j=precity[j]; 
   } 
   printf("\nTrack Way:"); 
   if (!traveltype) 
   { 
     for(i--;i>0;i--) 
	 { 
	   printf("\n%s:",cityname[track[i]]); 
	   end=track[i-1];min=32767; 
	   for (k=0;k<adjlist[track[i]].trainnum;k++) 
       if(adjlist[track[i]].train[k].endcity==end&&min>adjlist[track[i]].train[k].cost) 
	   { 
		 min=adjlist[track[i]].train[k].cost; 
	     tmp=k; 
	   } 
	   printf("%s   ",adjlist[track[i]].train[tmp].name);
	   startH=adjlist[track[i]].train[tmp].starttime/60 ;
	   startM=adjlist[track[i]].train[tmp].starttime%60 ;
       endH = adjlist[track[i]].train[tmp].stoptime/60 ;
       endM = adjlist[track[i]].train[tmp].stoptime%60 ;
       if( !(startH/10) )
	   {
	     printf("0");
	   }
	   printf("%d:",startH);
       if( !(startM/10) )
	   {
	     printf("0");
	   }
	   printf("%d -- ",startM);

	   if( !(endH/10) )
	   {
		 printf("0");
	   }
	   printf("%d:",endH);

	   if( !(endM/10) )
	   {
		 printf("0");
	   }
	   printf("%d\n",endM);
       printf("%2d:%2d-%2d:%2d",adjlist[track[i]].train[tmp].starttime/60,
	   adjlist[track[i]].train[tmp].starttime%60,adjlist[track[i]].train[tmp]
	   .stoptime/60,adjlist[track[i]].train[tmp].stoptime%60); 
	 } 
   } 
   else 
   { 
      for(i--;i>0;i--) 
	  { 
        printf("\n%s:",cityname[track[i]]); 
        end=track[i-1];min=32767; 
		for (k=0;k<adjlist[track[i]].flightnum;k++)
        if(adjlist[track[i]].flight[k].endcity==end&&min>adjlist[track[i]].flight[k].cost) 
		{ 
		   min=adjlist[track[i]].flight[k].cost; 
		   tmp=k; 
		} 
	    printf("%s",adjlist[track[i]].flight[tmp].name); 
        startH = adjlist[track[i]].flight[tmp].starttime / 60 ;
        startM = adjlist[track[i]].flight[tmp].starttime % 60;
        endH = adjlist[track[i]].flight[tmp].stoptime / 60 ;
        endM = adjlist[track[i]].flight[tmp].stoptime % 60 ;
        if( !(startH/10) )
		{
	       printf("0");
		}
        printf("%d:",startH);
        if( !(startM/10) )
		{
		   printf("0");
		}
    	printf("%d -- ",startM);

	    if( !(endH/10) )
		{
	    	printf("0");
		}
        printf("%d:",endH);
        if( !(endM/10) )
		{
	        printf("0");
		}
        printf("%d\n",endM);                    
        printf("%2d:%2d-%2d:%2d",adjlist[track[i]].flight[tmp]
		.starttime /60,adjlist[track[i]].flight[tmp].starttime%60,
		adjlist[track[i]].flight[tmp].stoptime /60,adjlist[track[i]].flight[tmp].stoptime % 60); 
	  } 
   } 
   printf("\n%s: DESTINATION!",cityname[track[0]]); 
   printf("\nMin Cost : %d\n",cost); 
}
void Dijkstra(int matx[Dij_max][Dij_max],int p_start,int p_end,int traveltype) 
{ 
int precity[Dij_max];                                     //PreCity[i]==-1,never used; 
                                                          //PreCity>0,the precity of City i 
    int i,j,min,pre,pos; 
    for (i=0;i<citynum;i++) 
	{ 
       precity[i]=-1; 
	} 
    precity[p_start]=-2; 
    while (precity[p_end]==-1) 
	{ 
       min=-1; 
       for (i=0;i<citynum;i++) 
       if (precity[i]!=-1) 
	   { 
          for (j=0;j<citynum;j++) 
          if(precity[j]==-1&&matx[i][j]>0&&(min<0||matx[i][j]<min)) 
		  { 
             pre=i;pos=j;min=matx[i][j]; 
		  } 
	   } 
       precity[pos]=pre; 
	 } 
     Dijkstra_output(matx,precity,p_end,traveltype); 
}
int initsysdata () 
{ 
  FILE *fp;
  int i,j,hour,minute,num,cost; 
  char stmp1[string_max]; 
  char stmp2[string_max]; 
  char stmp3[string_max]; 
  fp=fopen(cityfile,"r"); 
  if (!fp) 
  { 
      printf("\nError:Cannot Open City File...\n"); 
      return -1; 
  } 
     fscanf(fp,"%d",&citynum); 
     for (i=0;i<citynum;i++) 
	 { 
       fscanf(fp,"%s",&cityname[i]); 
       adjlist[i].city=i; 
       adjlist[i].trainnum=0; 
       adjlist[i].flightnum=0; 
	 } 
       fclose(fp); 
       fp=fopen(trainfile,"r"); 
       if (!fp) 
	  { 
          printf("\nError:Cannot Open Train File...\n"); 
          return -1; 
	  } 
      fscanf(fp,"%d",&num); 
      for (i=0;i<num;i++) 
	  { 
        fscanf(fp,"%s",&stmp1); 
        fscanf(fp,"%s",&stmp2); 
        fscanf(fp,"%s",&stmp3); 
        j=seekcity(stmp2); 
        adjlist[j].train[adjlist[j].trainnum].endcity=seekcity(stmp3); 
        strcpy(adjlist[j].train[adjlist[j].trainnum].name,stmp1); 
        fscanf(fp,"%d:%d",&hour,&minute); 
        adjlist[j].train[adjlist[j].trainnum].starttime=hour*60+minute; 
        fscanf(fp,"%d:%d",&hour,&minute); 
        adjlist[j].train[adjlist[j].trainnum].stoptime=hour*60+minute;  
		fscanf(fp,"%d",&cost);  
        adjlist[j].train[adjlist[j].trainnum].cost=cost; 
        adjlist[j].trainnum++; 
	  } 
      fclose(fp); 
      fp=fopen(flightfile,"r"); 
     if (!fp) 
	 { 
       printf("\nError:Cannot Open Flight File...\n"); 
       return -1; 
	 } 
     fscanf(fp,"%d",&num); 
     for (i=0;i<num;i++) 
	 { 
        fscanf(fp,"%s",&stmp1); 
        fscanf(fp,"%s",&stmp2); 
        fscanf(fp,"%s",&stmp3); 
        j=seekcity(stmp2); 
        adjlist[j].flight[adjlist[j].flightnum].endcity=seekcity(stmp3);            
	    strcpy(adjlist[j].flight[adjlist[j].flightnum].name,stmp1); 
		fscanf(fp,"%d:%d",&hour,&minute);               
		adjlist[j].flight[adjlist[j].flightnum].starttime=hour*60+minute; 
        fscanf(fp,"%d:%d",&hour,&minute);              
        adjlist[j].flight[adjlist[j].flightnum].stoptime=hour*60+minute; 
        fscanf(fp,"%d",&cost);  adjlist[j].flight[adjlist[j].flightnum].cost=cost; 
        adjlist[j].flightnum++; 
	 } 
     fclose(fp);
     return 1; 
}
int searchmintime (citytype city,citytype endcity,int curtime,int curpathno,int traveltype) 
{ 
   int i; 
   if (city==endcity) 
   { 
     if (mintime>curtime-starttime) 
	 { 
       for (i=0;i<=curpathno;i++) 
	   { 
           minpath[i].city=path[i].city; 
           minpath[i].trano=path[i].trano; 
           curpath=curpathno; 
	   } 
           mintime=curtime-starttime; 
	 } 
   } 
   else 
   { 
      curpathno++; 
      path[curpathno].city=city; 
      if (!traveltype) 
	  { 
         for (i=0;i<adjlist[city].trainnum;i++) 
		{ 
           if((adjlist[city].train[i].starttime>=(curtime%1440))&&
			 (adjlist[city].train[i].stoptime+(curtime/1440)*1440-starttime<mintime)) 
		   { 
              path[curpathno].trano=i;                              
			  searchmintime(adjlist[city].train[i].endcity,endcity,adjlist[city]
			  .train[i].stoptime+(curtime/1440)*1440,curpathno,traveltype); 
		   } 
           if((adjlist[city].train[i].starttime<(curtime%1440))&&
			  (adjlist[city].train[i].stoptime+(curtime/1440)*1440-starttime<mintime)) 
		   { 
              path[curpathno].trano=i;                                 
			  searchmintime(adjlist[city].train[i].endcity,endcity,adjlist[city].train[i]
			 .stoptime+(curtime/1440+1)*1440,curpathno,traveltype); 
		   } 
		 } 
	  } 
      else 
	  { 
       for (i=0;i<adjlist[city].flightnum;i++) 
	   { 
          if((adjlist[city].flight[i].starttime>=curtime)&&
			(adjlist[city].flight[i].stoptime+(curtime/1440)*1440-starttime<mintime))
		  { 
             path[curpathno].trano=i;                          
	         searchmintime(adjlist[city].flight[i].endcity,endcity,adjlist[city]
			 .flight[i].stoptime+(curtime/1440)*1440,curpathno,traveltype);
		  } 
          if((adjlist[city].flight[i].starttime<curtime)&&(adjlist[city].flight[i]
			  .stoptime+(curtime/1440)*1440-starttime<mintime)) 
		  { 
             path[curpathno].trano=i;                              
	         searchmintime(adjlist[city].flight[i].endcity,endcity,adjlist[city]
			.flight[i].stoptime+(curtime/1440+1)*1440,curpathno,traveltype); 
		  } 
	   } 
	  } 
   }
   return 1; 
}
int calcmintime (int startcity,int endcity,int traveltype) 
{ 
  int i;
  int startH, startM, endH, endM;              
  mintime=32767;curpath=0; 
  path[0].city=startcity; 
  if (!traveltype) 
  { 
    for (i=0;i<adjlist[startcity].trainnum;i++) 
	{ 
              path[0].trano=i; 
              starttime=adjlist[startcity].train[i].starttime; 
              searchmintime(adjlist[startcity].train[i].endcity,
			  endcity,adjlist[startcity].train[i].stoptime,0,traveltype);         
	} 
  } 
  else 
  { 
    for (i=0;i<adjlist[startcity].flightnum;i++) 
	{ 
       path[0].trano=i; 
       starttime=adjlist[startcity].flight[i].starttime;                
	   searchmintime(adjlist[startcity].flight[i].endcity,endcity,
	   adjlist[startcity].flight[i].stoptime,0,traveltype); 
	} 
  } 
  if (mintime==32767) 
  {
     printf("\nNo access to that destination!"); 
     return 0; 
  }
  if (!traveltype)
  starttime=adjlist[startcity].train[minpath[0].trano].starttime; 
  else 
  starttime=adjlist[startcity].flight[minpath[0].trano].starttime; 
  printf("\nPath:\n"); 
  for (i=0;i<=curpath;i++) 
  {
    if (!traveltype) 
    printf("%s : %s",cityname[minpath[i].city],adjlist[minpath[i].city].train[minpath[i].trano].name); 
    else
    printf("%s : %s",cityname[minpath[i].city],adjlist[minpath[i].city]
    .flight[minpath[i].trano].name);
    startH =adjlist[minpath[i].city].train[minpath[i].trano].starttime / 60 ;
    startM = adjlist[minpath[i].city].train[minpath[i].trano].starttime % 60 ;
    endH = adjlist[minpath[i].city].train[minpath[i].trano].stoptime / 60 ;
    endM = adjlist[minpath[i].city].train[minpath[i].trano].stoptime % 60 ; if( !(startH/10) )
	{
       printf("0");
	}
	printf("%d:",startH);
    if( !(startM/10) )
	{
	    printf("0");
	}
	printf("%d -- ",startM);
    if( !(endH/10) )
	{
      printf("0");
	}
    printf("%d:",endH);
    if( !(endM/10) )
	{
		printf("0");
	}
	printf("%d\n",endM);
	printf(" %2S:%2S-%2S:%2S\n",startH); 
  }
    printf("%s: DESTINATION!",cityname[endcity]); 
    printf("\nTime Cost: %2d hour - %2d minute",mintime/60,mintime%60); 
    return 1; 
}
int calcmincost (int startcity,int endcity,int traveltype) 
{ 
	int ma[Dij_max][Dij_max]; 
	int i,j,min,end; 
	for (i=0;i<citynum;i++) 
	for (j=0;j<citynum;j++) 
	ma[i][j]=-1; 
	if (traveltype==0) 
	{ 
	 for (i=0;i<citynum;i++) 
	 { 
	   min=32767;j=0; 
	   while (j<adjlist[i].trainnum) 
	   { 
	      min=32767; 
	      end=adjlist[i].train[j].endcity; 
	      while (end==adjlist[i].train[j].endcity&&j<adjlist[i].trainnum) 
		  { 
		     if (adjlist[i].train[j].cost<min) 
			 { 
		        min=adjlist[i].train[j].cost; 
			 } 
		     j++; 
		  } 
		  ma[i][end]=min; 
	   } 
	 } 
	} 
    else 
	{ 
       for (i=0;i<citynum;i++) 
	   { 
          min=32767;j=0; 
          while (j<adjlist[i].flightnum) 
		  { 
              min=32767; 
	          end=adjlist[i].flight[j].endcity; 
	          while (end==adjlist[i].flight[j].endcity&&j<adjlist[i].flightnum) 
			  { 
		         if (adjlist[i].flight[j].cost<min) 
				 { 
		            min=adjlist[i].flight[j].cost; 
				 } 
		         j++; 
			  } 
		      ma[i][end]=min; 
		  } 
	   } 
	} 
	Dijkstra(ma,startcity,endcity,traveltype); 
	return 1; 
}
int traffic() 
{ 
             char name[string_max];      
             char s_city[string_max];    
             char e_city[string_max]; 
             int command,cost; 
             int startcity,endcity,traveltype; 
             int s_hour,s_minute,e_hour,e_minute; 
             
             showmenu1();
             while (1) 
			 { 
                  showmenu2(); 
                  scanf("%d",&command);
                  switch (command) 
				  { 
                       case 0: "exit" ;
                               return 0; 
                       case 1: "add city"; 
                               initsysdata(); 
                               printf("input city name:"); 
                               scanf("%s",&name); 
                               insertcity(name); 
                               savesysinfo(); 
                               printf("System Info Save OK!\n"); 
                               break; 
                       case 2: "delete city";
                              initsysdata(); 
                              printf("input city name:"); 
                              scanf("%s",&name); 
                              delcity(name); 
                              savesysinfo(); 
                              printf("System Info Save OK!\n"); 
                              break; 
                       case 3: "add routing"; 
                              initsysdata(); 
                              printf("start city:"); 
                              scanf("%s",&s_city); 
                              printf("end city:"); 
                              scanf("%s",&e_city); 
                              printf("type（train0，flight1）:"); 
                              scanf("%d",&traveltype); 
                              printf("input train/flight class:"); 
                              scanf("%s",&name); 
                              printf("start time(00:00，24 hours):"); 
                              scanf("%2d:%2d",&s_hour,&s_minute); 
                              printf("arrive in time(00:00，24 hours):"); 
                              scanf("%2d:%2d",&e_hour,&e_minute); 
                              printf("price");scanf("%d",&cost); 
                              if (traveltype) 
							  { 
                                     insertflight(name,s_city,e_city,s_hour*60+s_minute,e_hour*60+e_minute,cost); 
							  } 
                              else 
							  { 
                                     inserttrain(name,s_city,e_city,s_hour*60+s_minute,e_hour*60+e_minute,cost); 
							  } 
                              savesysinfo(); 
                              printf("System Info Save OK!\n"); 
                              break; 
                      case 4:"delete routing"; 
                              initsysdata(); 
                              printf("input class:"); 
                              scanf("%s",&name); 
                              delpath(name); 
                              savesysinfo(); 
                              printf("System Info Save OK!\n"); 
                              break; 
                      case 5: "minimum cost"; 
                             initsysdata(); 
                             printf("start city:"); 
                             scanf("%s",&name); 
                             startcity=seekcity(name); 
                             if (startcity<0) 
							 { 
                                    printf("Error City Name:No such city!\n"); 
                                    break; 
							 } 
                             printf("end city:"); 
                             scanf("%s",&name); 
                             endcity=seekcity(name); 
                             if (endcity<0) 
							 { 
                                      printf("Error City Name:No such city!\n"); 
                                      break; 
							 } 
                             printf("type(train0,flight1) :"); 
                             scanf("%d",&traveltype); 
                             if (traveltype!=0&&traveltype!=1) 
							 { 
                                 printf("Error Input!"); 
                                 break; 
							 } 
                             calcmincost(startcity,endcity,traveltype); 
                             printf("\n"); 
                             break; 
                     case 6: "minmum time routing"; 
                             initsysdata(); 
                             printf("start city:"); 
                             scanf("%s",&name); 
                             startcity=seekcity(name); 
                             if (startcity<0) 
							    { 
                                printf("Error City Name:No such city!\n"); 
                                break; 
							 } 
                             printf("end city:"); 
                             scanf("%s",&name); 
                             endcity=seekcity(name); 
                             if (endcity<0) 
							 { 
                                  printf("Error City Name:No such city!\n"); 
                                  break; 
							 } 
                             printf("type(train0,flight1) :"); 
                             scanf("%d",&traveltype); 
                             if (traveltype!=0&&traveltype!=1) 
							 { 
                                  printf("Error Input!"); 
                                  break; 
							 }  
                              calcmintime(startcity,endcity,traveltype); 
                          printf("\n"); 
                          break; 
                   } 
            } 
            return 0;
}
