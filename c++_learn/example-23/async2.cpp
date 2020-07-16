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




int main(){
	cout<<" starting fun1() in background"
	    <<" and fun2() in foreground: "<<std::endl;
	
//	std::future<int> result1(std::async(func1));

	auto f1 = std::async([]{doSomething('.');});
	auto f2 = std::async([]{doSomething('+');});
	
	if(f1.wait_for(chrono::seconds(0)) != future_status::deferred || f2.wait_for(chrono::seconds(0)) != future_status::deferred)
	{
		while(f1.wait_for(chrono::seconds(0)) != future_status::ready && f2.wait_for(chrono::seconds(0) )!= future_status::ready){
			this_thread::yield();			
		}

	}
	cout.put('\n').flush();
	try{
		f1.get();
		f2.get();
	}
	catch(const exception& e){
		cout<<"\n exception :"<<e.what()<<endl;
	}
	cout <<"\n done"<<endl;
}
