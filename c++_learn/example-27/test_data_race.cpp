#include <iostream>
#include <vector>
#include <thread>

#define N 4

void* thread_t(int argp){
	int myid = argp;
	printf("Hello from thread %d\n",myid);
	return NULL;
}

int main(){
	int i;
	std::vector<std::thread> thread_vec_;
	for(i = 0;i<N;++i)
	{
		thread_vec_.push_back(std::thread(thread_t,i));
	}
	for(i = 0;i<N;++i){
		thread_vec_[i].join();
	}
	exit(0);
}


