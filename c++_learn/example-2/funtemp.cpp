#include <iostream>

template <typename T>
void Swap(T &a,T &b);


int main(){
	using namespace std;
	int i = 10;
	int j=20;
	cout<<"i,j =" <<i <<", "<<j<<".\n";
	cout<<"Using complier generated int swaper :\n";
	Swap(i,j);
	cout<<"now i,j = "<<i <<", "<<j<<".\n";


	double x = 24.5;
	double y = 81.7;
	cout<<"x,y =" <<x <<", "<<y<<".\n";
	cout<<"Using complier generated double swaper :\n";
	Swap(x,y);
	cout<<"now x,y = "<<x <<", "<<y<<".\n";
	return 0;
}


template <typename T>
void Swap(T &a,T &b){
	T temp;
	temp=a;
	a=b;
	b=temp;
}

