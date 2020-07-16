#include <iostream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const string& thread_name){
	++rage;
	lock_guard<mutex>lock(cout_mutex);
	cout<<"Rage counter for "<<thread_name<<": "<<rage<<endl;
}


int main(){
	thread a(increase_rage,"a");
	thread b(increase_rage,"b");
	
	{
		lock_guard<mutex>lock(cout_mutex);
		cout<<"Rage counter for  main : "<<rage<<endl;
	}
	
	a.join();
	b.join();

	{
		lock_guard<mutex>lock(cout_mutex);
		cout<<"Rage counter for  main : "<<rage<<endl;
	}
}
