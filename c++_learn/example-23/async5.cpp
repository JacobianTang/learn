#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <mutex>

using namespace std;

bool readyFlag ;
mutex readyFlagMutex ;

void thread1(){
	//do something thread2 needs as preparation
	
	std::lock_guard<mutex> lg(readyFlagMutex);
	readyFlag = true;

}

void thread2(){
	{
		unique_lock<mutex> ul(readyFlagMutex);
		while(!readyFlag){
			ul.unlock();
			std::this_thread::yield();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			ul.lock();
		}
	}//release lock

}

int main(){
	auto f1 = async(launch::async,thread1);
	auto f2 = async(launch::async,thread2);
	f1.wait();
	f2.wait();
	cout<<"hello from the main thread"<<endl;
}
