#include<stdio.h>
#include<pthread.h>
#define BUFFER_SIZE 16
struct prodcons
{
	int buffer[BUFFER_SIZE];
	pthread_mutex_t lock;
	int readpos;
	int writepos;
	pthread_cond_t notempty;
	pthread_cond_t notfull;
};

void pthread_init(struct prodcons *p)
{
	pthread_mutex_init(&p->lock,NULL);
	pthread_cond_init(&p->notempty,NULL);
	pthread_cond_init(&p->notfull,NULL);
	p->readpos=0;
	p->writepos=0;
}

void put(struct prodcons *p,int data)
{
	pthread_mutex_lock(&p->lock);
	if((p->writepos+1)%BUFFER_SIZE==p->readpos)
	{
		pthread_cond_wait(&p->notfull,&p->lock);
	}
	p->buffer[p->writepos]=data;
	p->writepos++;
	if(p->writepos>=BUFFER_SIZE)
	{
		p->writepos=0;
	}
	pthread_cond_signal(&p->notempty);
	pthread_mutex_unlock(&p->lock);
 } 
 
 int get(struct prodcons *p)
 {
 	int data;
 	pthread_mutex_lock(&p->lock);
 	if(p->writepos==p->readpos)
 	{
 		pthread_cond_wait(&p->notempty,&p->lock);
	}
	data=p->buffer[p->readpos];
	p->readpos++;
	if(p->readpos==BUFFER_SIZE)
	{
		p->readpos=0;
	}
	pthread_cond_signal(&p->notfull);
	pthread_mutex_unlock(&p->lock);
	return data;
 }
 
 
 #define OVER -1
 struct prodcons buffer;
 void *producer(void *data)
 {
 	int n;
 	for(n=0;n<10;n++)
 	{
 		printf("%d----------->\n",n);
 		put(&buffer,n);
	}
	put(&buffer,OVER);
	return NULL;
 }
 
 void *consumer(void *data)
 {
 	int d;
 	while(1)
 	{
 		d=get(&buffer);
 		if(d==OVER)
 		{
 			break;
		}
		else
		{
			printf("----------->%d\n",d);
		}
	}
	return NULL;
 }
 
 
 int thread()
 {
 	pthread_t th_p,th_c;
 	void *retval;
 	pthread_init(&buffer);
 	pthread_create(&th_p,NULL,producer,0);
 	pthread_create(&th_c,NULL,consumer,0);
 	
 	pthread_join(th_p,&retval);
 	pthread_join(th_c,&retval);
 	return 0;
 }
