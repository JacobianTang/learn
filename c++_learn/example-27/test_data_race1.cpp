#include <semaphore.h>
#include <iostream>

#define N 4

void* thread_t(void* argp){
	int myid = *((int*)argp);
	//free(argp);
	printf("Hello from thread %d\n",myid);
	return NULL;
}

int main(){

	pthread_t tid[N];
	int i;

	for(i = 0;i<N;++i)
	{
		//int* index = (int*)malloc(sizeof(int));
		//*index = i;
		int index = i;
		std::cout<<(void*)(&index)<<std::endl;
		pthread_create(&tid[i],NULL,thread_t,&index);
	}

	for(i = 0;i<N;++i){
		pthread_join(tid[i],NULL);
	}
	exit(0);
}


