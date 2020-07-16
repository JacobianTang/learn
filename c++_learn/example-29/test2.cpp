#include <iostream>
#include <thread>
#include <functional>

using namespace std;
using namespace std::placeholders;

class Person{
	private:
		string name;
	public:
		Person(const string& n):name(n){
		
		}
#if 0
		void print(){
			cout<<name<<endl;
		}
#endif

#if 1
		void print(const int& score){
			cout<<name<<"  "<<score<<endl;
		}
#endif
};


template<class Function,class...Args>
void print_test(Function&& f,Args... test){
	f(test...);
}


int main(){
	Person t("tangqi");
	//auto f = std::bind(&Person::print,_1,_2);
	//f(&t,100);

	auto f=std::bind(&Person::print,t,_1);
	print_test(f,100);
	thread tmp(f,10);
	tmp.join();
}
