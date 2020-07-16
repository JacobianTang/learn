#include <iostream>
#include <pthread.h>
#include <chrono>
#include <string>
#include <cstring>
#include <semaphore.h>
#if 0
#include <mutex>
#include <thread>
std::mutex data_mutex;
#endif

int cnt = 0;

sem_t* mutex;

//sem_t mutex;

void* thread(void* argp){
	int i ;
	int niters = *(int*)argp;
	
	for(i =0;i<niters;++i){
		//std::lock_guard<std::mutex> lg(data_mutex);
		sem_wait(mutex);
		cnt++;
		sem_post(mutex);
	}

	return NULL;
}

int  main(){
	//sem_init(&mutex,0,1);
	mutex=sem_open("yoursem",O_CREAT, S_IRUSR | S_IWUSR, 1);
	pthread_t tid1,tid2;
	int niters = 1000;
	pthread_create(&tid1,NULL,thread,&niters);
	pthread_create(&tid2,NULL,thread,&niters);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	if(cnt != (2*niters)){
		printf("%d ---%d\n",cnt,2*niters);
	}else{
		printf("%d ---%d\n",cnt,2*niters);
	}

	pthread_exit(NULL);
}
