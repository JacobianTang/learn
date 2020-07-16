#include <iostream>
using namespace std;

class Foo{
public:
		Foo(){
			cout<<"init\n";
		}
		Foo(const Foo& copy_){
			cout<<"copy init\n";
		}
		~Foo(){
			cout<<"del\n";
		}
private:
		int x;
		int y;

};


Foo return_foo(){
	{
		Foo foo;
		return foo;
	}
}

void caller_foo(Foo foo){
	;	
}

int main(){
	{
		Foo rtn = return_foo();
		caller_foo(rtn);
	}
}
