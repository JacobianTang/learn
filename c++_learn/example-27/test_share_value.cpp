#include <iostream>
#include <pthread.h>
#include <chrono>
#include <string>
#include <cstring>
#include <semaphore.h>
#include <thread>
#include <vector>
using namespace std;
sem_t mutex;
#define N 2

char** ptr;

void* thread0(void* argp){
	int myid = *(int*)argp;
	static int cnt = 0;
	printf("[%d]:%s(cnt =%d)\n",myid,ptr[myid],++cnt);
	return NULL;

}

void* thread1(int argp){
	int myid = argp;
	static int cnt = 0;
	printf("[%d]:%s(cnt =%d)\n",myid,ptr[myid],++cnt);
	return NULL;

}

int  main(){
    //pthread_t tid;
	char* msgs[N]={"Hello from foo","Hello from bar"};

	ptr = msgs;
	//int* ptrN[N];
	int ptr[N]={0};
	vector<thread> thread_vec;
	//std::thread thread_vec[N];

	for(int i = 0;i<N;i++)
	{
	//	int* index = (int*)malloc(sizeof(int));
	//	*index =i;
	//	ptr[i] = i;
	//	pthread_create(&tid,NULL,thread,&ptr[i]);
		//std::thread t(thread1,i);
		thread_vec.push_back(std::thread(thread1,i));
		//thread_vec[i]=t;
		printf("%d\n",i);
	}
	for(int i =0;i<N;++i){
		thread_vec[i].join();
	}

//	for(int i =0;i<N;i++){
//		free(ptrN[i]);
//	}
	//pthread_exit(NULL);
}




