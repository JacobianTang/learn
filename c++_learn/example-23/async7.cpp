#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <mutex>
#include <condition_variable>
#include <queue>


using namespace std;

queue<int> int_queue;
mutex queueMutex;
condition_variable queueConVar;
int provide_num =0;
int consumer_num =0;

void provider(int val){
	for(int i = 0;i<6;++i){
		lock_guard<mutex> lg(queueMutex);
		int_queue.push(val +i);
		provide_num++;
		cout<<"provider :"<<val +i<<endl;
	}
	queueConVar.notify_one();
	std::this_thread::sleep_for(chrono::milliseconds(val));
}

void consumer(int num){
	while(true){
		int val;
		if(consumer_num >=18){
			break;
		}
		{
			unique_lock<mutex> ul(queueMutex);
			queueConVar.wait(ul,[]{return !int_queue.empty() || consumer_num ==18 ;});
			if(!int_queue.empty()){
				val = int_queue.front();
				int_queue.pop();
				consumer_num++;
				std::cout<<"consumer "<<num <<" : "<<val <<" "<<consumer_num<<endl;
			}
		}//release lock
	}//release lock
	std::cout<<"done"<<std::endl;
}

int main(){
	auto p1 = async(launch::async,provider,100);
	auto p2 = async(launch::async,provider,300);
	auto p3 = async(launch::async,provider,500);
	auto c1 = async(launch::async,consumer,1);
	auto c2 = async(launch::async,consumer,2);
	cout<<"hello from the main thread"<<endl;
}
