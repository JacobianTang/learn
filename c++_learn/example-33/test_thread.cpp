#include <thread>
#include <iostream>
#include <string>
using namespace std;

void global_caller(const string& str){
	std::cout<<"global_caller:"<<str<<std::endl;
}

class Clc{
public:
	Clc()=default;
	
	Clc(const string& name,int data):name_(name),data_(data){
	//	print("welcome");	
	}
	~Clc(){
	
	}
	void print(const string& test_str){
		std::cout<<"test_str:"<<test_str<<std::endl;
	}
	static void access_add(const string& test_str){
		access_num++;
		std::cout<<test_str<<"   " <<access_num<<std::endl;
	}
	
	void invoke(const string& print_str){
		std::cout<<"begin...:"<<print_str<<std::endl;
		thread t(&Clc::print,this,"welcome");
		t.join();
		thread t1(access_add,"call static from class");
		t1.join();
		std::cout<<"done..."<<std::endl;
	}
private:
	static int access_num;
	string name_;
	int data_;
};
int Clc::access_num=0;


int main(){
	thread t(global_caller,"hello");
	t.join();
	
	thread static_t(&Clc::access_add,"call staitc from main");
	static_t.join();
	
	Clc clcer("tangqi",100);
	thread main_t(&Clc::invoke,clcer,"call");
	main_t.join();
}
