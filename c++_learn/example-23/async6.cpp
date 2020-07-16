#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <mutex>
#include <condition_variable>
using namespace std;

bool readyFlag ;
mutex readyFlagMutex ;
condition_variable readyConVar;

void thread1(){
	//do something thread2 needs as preparation
	
	std::cout<<"<return>"<<std::endl;
	std::cin.get();

	{
		std::lock_guard<mutex> lg(readyFlagMutex);
		readyFlag = true;
	
	}
	readyConVar.notify_one();
}

void thread2(){
	{
		unique_lock<mutex> ul(readyFlagMutex);
		while(!readyFlag){
			readyConVar.wait(ul);
		}
	}//release lock
	std::cout<<"done"<<std::endl;
}

int main(){
	auto f1 = async(launch::async,thread1);
	auto f2 = async(launch::async,thread2);
	//f1.wait();
	//f2.wait();
	cout<<"hello from the main thread"<<endl;
}
