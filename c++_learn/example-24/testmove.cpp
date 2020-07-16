#include <iostream>
using namespace std;
template<typename T>
void f(T&& param){
	cout<<"value:"<<param<<endl;
}


int main(){
	f(10);
	int x = 11;
	f(x);

}
