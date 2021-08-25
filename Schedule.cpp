#include<stdlib.h> 
# include<conio.h> 
# include<stdio.h>  
# define pagesize 3              //页面尺寸大小  
typedef struct BLOCK      //声明一种新类型--物理块类型
 {   	
      int pagenum;          //页号 	
      int accessed;         //访问量，其值表示多久未被访问 
  }BLOCK;
                        //程序计数器，用来记录对应的页号 
                       //缺页计数器，用来记录缺页的次数	 
      static int num[10];         //用来存储20条随机数 
      BLOCK block[pagesize];      //定义一大小为3的物理块数组 
       void init()  
       {    
         int i;   
         for(i=0;i<pagesize;i++)  	
         {          
             block[i].pagenum=-1;                     
             block[i].accessed=0;        	
          } 
       } 
    int findExist(int curpage) 
    {     
         int i;
         for(i=0; i<pagesize; i++) 	
         {                       
             if(block[i].pagenum == curpage )         
             return i;              //检测到内存中有该页面，返回block中的位置 	
         }             
         return -1; 
     }  
     int findSpace() 
     {       
         int i;
         for(i=0;i<pagesize;i++)    
        {         
             if(block[i].pagenum==-1)        
             return i;   //找到空闲的block，返回block中的位置    
         }  	    
         return -1; 
      }  
     int findReplace() 
    {     
        int pos = 0;  
        int i;  
        for(i=0;i<pagesize;i++)     
        {            
            if(block[i].accessed>block[pos].accessed)         
            pos = i;                           //找到应该置换页面，返回BLOCK中位置    
         }    
         return pos; 
     }   
     void display() 
    {    
         int i;	
         for(i=0; i<pagesize; i++) 
   	{    		
           if(block[i].pagenum != -1) 		
           { 	     
              printf(" %2d",block[i].pagenum); 		
            } 	
         } 	
         printf("\n"); 
     }  
     void randam() 
    {  
       int pc; 
       int flag=0;    
       int i;
       scanf("%d",&pc);     
       printf("******Generate 30 random numbers as required:*******\n");    
       for(i=0;i<30;i++) 	
       {             
          num[i]=pc; 		
          if(flag%2==0)  			
          pc=++pc%30;         
          if(flag==1)  			
          pc=rand()%(pc-1);         
          if(flag==3)  			
          pc=pc+1+(rand()%(30-(pc+1)));         
          flag=++flag%4; 		
          printf(" %3d",num[i]);         
          if((i+1)%10==0)  		
          printf("\n"); 	
        }  
     } 
     void pagestring()         //显示调用的页面队列,页面号取法为随机数除10取整 
     {       
        int i;
        for(i=0;i<30;i++) 	
        { 	   
             printf(" %2d",num[i]/10);       
             if((i+1)%10==0)  	  
             printf("\n"); 	
         }
      }  
      void OPT()        //最佳替换算法 
     {    	
        int pc,n=0;
        int exist,space,position; 	
        int curpage;   
        int i,j;  
        for(i=0;i<30;i++) 	
        {    		
           pc=num[i];  	    
           curpage=pc/10; 	    
           exist=findExist(curpage);        
           if(exist==-1) 		
           {   			
              space=findSpace();            
              if(space != -1) 			
              {    				                  
                  block[space].pagenum = curpage;                  
                  display(); 			    
                //  n=n+1; 			
               }             
               else 			
               {     				   
                   for(j=i;j<30;j++) 					
                   { 						
                        if(block[i].pagenum!= num[j]/10)                                                         					
                        {  					   
                            block[i].accessed = 1000;  						
                         }                                          //将来不会用，设置为一个很大数                        
                         else 	                               
		                 {    							
                              block[i].accessed = j; 							
                              break;	 						
                          } 					
                    } 				
                }                      
                position = findReplace();                       
                block[position].pagenum = curpage;                        
                display();
 	        n++;			 			
            } 		
         } 	
         printf("Page missing times:%d\n",n); 	
         printf("Page fault rate:%f%%\n",(n/30.0)*100);
     }  
     void LRU()         //最近最久未使用算法 
     {    	
         int exist,space,position ; 	
         int curpage;   
         int i,j; 
		 int pc,n=0;         
         for(i=0;i<30;i++) 	
         {   		
             pc=num[i];  	    
             curpage=pc/10; 	    
             exist = findExist(curpage);        
             if(exist==-1) 		
             {  
                space = findSpace();             
                if(space != -1) 			
                {   				
                    block[space].pagenum = curpage;                  
                    display(); 			           
                    n=n+1;
                 }             
                 else 			
                 {   				
                    position = findReplace();                    
                    block[position].pagenum = curpage;                     
                    display(); 			 	
                //    n++;			 			
                  } 		
              }     
              else  		
              block[exist].accessed = -1;//恢复存在的并刚访问过的BLOCK中页面accessed为-1        
              for(j=0; j<pagesize; j++)         
              { 			
                 block[j].accessed++; 		
               } 	
           } 		  
           printf("Page missing times:%d\n",n); 	
           printf("Page fault rate:%f%%\n",(n/30.0)*100);
     }  
     void FIFO()       //先进先出算法 
     {       
     	  int pc,n=0;
          int exist,space,position ; 	
          int curpage;  
          int i,j;  
          for(i=0;i<30;i++) 	
          {    		
             pc=num[i];              	     
             curpage=pc/10;          //转换为页面号       	
             exist = findExist(curpage);     // 查找物理块中是否有该页面,没有的话，置为-1       
             if(exist==-1)        	    
             { 			
                 space = findSpace();      //查找是否有空的物理块，没有的话，置为-1；有的话，把位置返回               
                 if(space != -1) 			       
                 {    				  
                     block[space].pagenum=curpage;                     
                     display(); 			       
                     //n=n+1; 			  
                  }                
                  else 			  
                  {   				  
                      position = findReplace();   // 没有空闲物理块，进行置换                   
                      block[position].pagenum = curpage;         
                      display(); 			 	  
                      n++; 			       
                      block[position].accessed--; 			  
                   } 		
             } 		     
             for(j=0; j<pagesize; j++)      //把所有在页面里的页面号的访问次数加1             
             block[j].accessed++; 	
          } 	
          printf("Page missing times:%d\n",n); 	
          printf("Page fault rate:%f%%\n",(n/30.0)*100);
    } 
                 
      int schedule() 
     {     
         int  select;   
         printf("Please input first random number(0~30):");   
         randam();   
         printf("*****Call page queue*******\n");   
         pagestring();  
        do   
        {   	 
             printf("****************************************\n");
             printf("------1:OPT   2:LRU  3:FIFO  4:EXIT-----\n");       
             printf("****************************************\n");       
             printf("Please select a page replacement algorithm:");  	  
             scanf("%d",&select);       
             printf("*******************************\n"); 	  
             init(); 	  
             switch(select) 	  
             {  	   
                 case 1: 	         
                        printf("OPT:\n");              
                        printf("*****************\n");                                  
						OPT(); 	        
                        break;        
                 case 2: 		    
                        printf("LRU:\n");             
                        printf("*************************\n");              
                        LRU();             
                        break;        
                 case 3: 		     
                        printf("FIFO:\n"); 
            		    printf("*********************\n");              
                        FIFO(); 	        
                        break; 	  
              }         
        }while(select!=4);
        return 0;
    }  
   
