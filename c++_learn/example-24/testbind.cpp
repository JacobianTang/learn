#include <functional>
#include <iostream>
using namespace std;
using namespace std::placeholders;

int add(int a,int b){
	return a+b;
}

int main(){
	auto plus_op = plus<int>();
	cout<<plus_op(2,3)<<endl;

	int ten =10;
	int two =2;
	auto plus_ten_time_two =bind(multiplies<int>(),
			bind(plus_op,placeholders::_1,ten),two);


	auto divide_op = divides<int>();
	
	auto divide_inver_op =bind(divides<int>(),placeholders::_2,placeholders::_1);
	
	cout<<divide_inver_op(3,2)<<endl;


	auto add_ten=bind(add,_1,10);
	
	cout<<add_ten(3)<<endl;
}
