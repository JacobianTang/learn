#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int dosomething(char c){
	////random-number generator (use c as seed to get different sequences)
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10,1000);
	for(int i=0;i<10;++i){
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}	
	return c;
}

int queryNumber(){
	cout<<"read number: ";
	int num ;
	cin>>num;
	if(!cin){
		throw runtime_error("no number read");
	}
	return num;
}

void doSomething(char c,shared_future<int> f){
	try{
		int num = f.get();//get result of queryNumber
		for(int i=0;i<num;++i){
			this_thread::sleep_for(chrono::milliseconds(100));
			cout.put(c).flush();
		}	
	}
	catch(const exception &e){
		cerr<<"exception in thread "<<this_thread::get_id()<< " : "<<e.what()<<endl;
	}
}

int main(){
	try{
		shared_future<int> f = async(queryNumber);
		f.get();
		
		auto f1 = async(launch::async,doSomething,'.',f);
		auto f2 = async(launch::async,doSomething,'+',f);
		auto f3 = async(launch::async,doSomething,'*',f);

		f1.get();
		f2.get();
		f3.get();
	}
	catch(const exception& e){
		cout<<"\nexception"<<e.what()<<endl;
	}

	cout<<"\n done ";
}
