#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <thread>
#include <chrono>
int writecnt = 0;
sem_t mutex_sem;//protect writecnt
sem_t read_sem; //awaken reader
void* writer(void* )
{

	while(1){
		sem_wait(&mutex_sem);
		writecnt++;
		if(writecnt ==1){
			sem_wait(&read_sem);
		}
		sem_post(&mutex_sem);

		printf("I am writing\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(2));
		sem_wait(&mutex_sem);
		writecnt--;
		if(writecnt==0){
			sem_post(&read_sem);
		}
		sem_post(&mutex_sem);
	}

	return NULL;
		
}
void* reader(void* ){
	while(1){
		sem_wait(&read_sem);
		printf("I am reading\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		sem_post(&read_sem);
	}
	return NULL;
}

int  main(){

	sem_init(&read_sem,0,1);
	sem_init(&mutex_sem,0,1);
	pthread_t read_tid;
	pthread_t write_tid;

	pthread_create(&read_tid,NULL,reader,NULL);
	pthread_create(&write_tid,NULL,writer,NULL);

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	pthread_cancel(read_tid);

	pthread_join(read_tid,NULL);
	//pthread_join(write_tid,NULL);
	//pthread_exit(NULL);

}




