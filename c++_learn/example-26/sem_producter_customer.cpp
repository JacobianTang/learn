#include <iostream>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>

struct  sbuf_t{
	int* buf;
	int n;
	int front;
	int rear;
	sem_t mutex;
	sem_t slots;//counts available slots
	sem_t items;//counts available items
};

void sbuf_init(sbuf_t* sp,int n){
	sp->buf = (int*)calloc(n,sizeof(int));
	sp->n=n;
	sp->front=sp->rear =0;
	sem_init(&sp->mutex,0,1);//binary semaphore for locking
	sem_init(&sp->slots,0,n);//initially,buf has n empty slots;
	sem_init(&sp->items,0,0);//initially,buf has zero data items;
}


void* producter(void* t){
	int item = 0;
	sbuf_t * sp=(sbuf_t *)t;
	while(1){
		item++;
		sem_wait(&sp->slots);
		sem_wait(&sp->mutex);
		sp->buf[sp->rear%sp->n]=item;
		sp->rear++;
		printf("producter :%d\n",item);
		sem_post(&sp->mutex);
		sem_post(&sp->items);
	}
}

void* customer(void* t){
	sbuf_t* sp=(sbuf_t*)t;
	int item = 0;
	while(1){
		sem_wait(&sp->items);
		sem_wait(&sp->mutex);
		item = sp->buf[sp->front%sp->n];
		sp->front++;
		printf("customer :%d\n",item);
		sem_post(&sp->mutex);
		sem_post(&sp->slots);
	}
}


sbuf_t sp;

int  main(){
	sbuf_init(&sp,100);
	pthread_t cus_tid;
	pthread_t pro_tid;

	pthread_create(&cus_tid,NULL,customer,(void*)&sp);
	pthread_create(&pro_tid,NULL,producter,(void*)&sp);

	pthread_join(cus_tid,NULL);
	pthread_join(pro_tid,NULL);
	pthread_exit(NULL);

}
