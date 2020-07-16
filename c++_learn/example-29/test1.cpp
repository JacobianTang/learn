#include <iostream>

using namespace std;

void function_overload(int i,int d =5){
	cout<<i<<d<<endl;
}
#if 1
void function_overload(int i,int d=5,int c=6)
{
	cout<<i<<d<<endl;
	cout<<"good"<<endl;
}
#endif

int main(){
//	function_overload(5,5);
}
