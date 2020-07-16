#include <future>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex dataMutex;
int count = 0;

void print_str(const string& str){
	cout<<"thread id :"<<this_thread::get_id()<<endl;
	while(true){
		{
			lock_guard<std::mutex>lg(dataMutex);
			if(count >= 100){
				break;
			}
			count++;
		    cout<<count<< " " <<str<<endl;
		}
	}
}

int main(){
	future<void> f1 = async(print_str,"hello world");

	future<void> f2 = async(print_str,"gcc");
	
	future<void> f3 = async(print_str,"g++");
	
	future<void> f4 = async(print_str,"c++");
	future<void> f5 = async(print_str,"hxlx");
	cout<<"done.\n";
	//f.get();

}

