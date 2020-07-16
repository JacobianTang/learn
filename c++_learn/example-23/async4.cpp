#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <mutex>

using namespace std;

mutex printMutex;//enable synchroinze output with print()

void print(const std::string& s){
	std::lock_guard<std::mutex> lg(printMutex);
	for(char c:s){
		std::cout.put(c);
	}
	std::cout<<std::endl;
}


int main(){
	auto f1 = async(launch::async,print,"hello from a first thread");
	auto f2 = async(launch::async,print,"hello from a second thread");
	f1.wait();
	f2.wait();
	print("hello from the main thread");
}
