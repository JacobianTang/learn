#include <iostream>
#include <string>
#include "stcktp1.h"
#include "arraytp.h"

template<int n> 
class ArrayTp<char*,n>{
private:
	char* ar[n];
public:
	ArrayTp(){}
};



typedef ArrayTp<double,12> arrd;

template class Stack<double>;
template class Stack<int>;

template<typename T1,typename T2>
class Pair{
private:
	T1 a;
	T2 b;
public:
	Pair(const T1& aval,const T2& bval):a(aval),b(bval){
	
	}
	Pair(){
	}
	
	T1& first();

	T2& second();
	
	T1 first()const{
		return a;
	}
	
	T2 second()const{
		return b;	
	}
};


template<typename T1,typename T2>
T1& Pair<T1,T2>::first(){
	return a;
}

template<typename T1,typename T2>
T2& Pair<T1,T2>::second(){
	return b;
}

template class Pair<int,int>;


int main(){
	using std::cout;
	using std::endl;
	using std::string;
	ArrayTp<char*,10> ArrayPtr;
	arrd gallons;

	Pair<string,int> ratings[4]={
		Pair<string,int>("The Purpled Duck",5),
		Pair<string,int>("Jaquie's Frisco AI Fresco",4),
		Pair<string,int>("Cafe Souffle",5),
		Pair<string,int>("Bertie's Eats",3)
	};

	int joints = sizeof(ratings)/sizeof(Pair<string,int>);

	for(int i=0;i<joints;++i){
		cout<<ratings[i].second()<<":\t"
			 <<ratings[i].first()<<endl;
		
	}

	cout<<"Oops ! Revised ratings:\n";

	ratings[3].first()="Bertie's Fab Eats";
	ratings[3].second()=6;

	for(int i=0;i<joints;++i){
		cout<<ratings[i].second()<<":\t"
			 <<ratings[i].first()<<endl;
		
	}

}
