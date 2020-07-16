#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething(char c){
	////random-number generator (use c as seed to get different sequences)
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10,1000);
	for(int i=0;i<10;++i){
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}	

	return c;
}


int func1(){
	return 	doSomething('.');
}

int func2(){
	return doSomething('+');
}


int main(){
	cout<<" starting fun1() in background"
	    <<" and fun2() in foreground: "<<std::endl;
	
	std::future<int> result1(std::async(func1));

	int result2 = func2();

	int result = result1.get() + result2;

	cout <<"\n result of func2() + func1() : "<< result<<endl;


}
