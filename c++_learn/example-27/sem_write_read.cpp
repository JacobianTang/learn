#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <thread>
#include <chrono>
int readcnt = 0;
sem_t mutex_sem;//protect readcnt
sem_t writer_sem; //awaken writer
void* reader(void* )
{

	while(1){
		sem_wait(&mutex_sem);
		readcnt++;
		//只要有人就要阻塞writer，后面的读者如果发现
		//有人没有必要重复加锁
		if(readcnt ==1){
			sem_wait(&writer_sem);
		}
		sem_post(&mutex_sem);

		printf("I am reading\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		sem_wait(&mutex_sem);
		readcnt--;
		///如果没有读者了，可以唤醒writer
		if(readcnt==0){
			sem_post(&writer_sem);
		}
		sem_post(&mutex_sem);
	}

	return NULL;
		
}



void* writer(void* ){
	while(1){
		sem_wait(&writer_sem);
		printf("I am writing\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		sem_post(&writer_sem);
	}
	return NULL;
}





int  main(){

	sem_init(&writer_sem,0,1);
	sem_init(&mutex_sem,0,1);
	pthread_t read_tid;
	pthread_t write_tid;

	pthread_create(&read_tid,NULL,reader,NULL);
	pthread_create(&write_tid,NULL,writer,NULL);

	pthread_join(read_tid,NULL);
	pthread_join(write_tid,NULL);
	pthread_exit(NULL);

}




