#include <iostream>

void countdown(int n);

int main(){
	countdown(4);
	return 0;
}

void countdown(int n){
	using namespace std;
	cout<<"counting down ... " << n << " ( n at "<< &n << ")"<<endl;
	if(n >0)
		countdown(n-1);
	cout<< n << "; kaboom!"<< " ( n at "<< &n << ")"<<endl;
}
	
