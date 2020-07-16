#include <iostream>
#include "studentc.h"

using std::endl;
using std::cin;
using std::cout;

const int pupils = 3;
const int quizzes = 5;


void set(Student& sa,int n){
	cout <<"Please enter the student's name: ";
	getline(cin,sa);
	cout<<"Please enter "<<n <<" quiz scores: \n";
	for(int i=0;i<n;++i){
		cin>>sa[i];
	}
	while(cin.get() != '\n'){
		continue;
	}

}

int main(){

	Student ada[pupils] = {
		Student(quizzes),
		Student(quizzes),
		Student(quizzes)
	};
	int i;
	
	
	for( i= 0;i<pupils;++i){
		set(ada[i],quizzes);
	}

	cout<<"\n Student List :\n";

	for( i= 0;i<pupils;++i){
		cout<<ada[i].Name()<<endl;	
	}

	cout<<"\nResult: ";
	for( i= 0;i<pupils;++i){
		cout<<endl<<ada[i];
		cout<<"average: "<<ada[i].Average()<<endl;	
	}
	cout<<"done .\n";
	return 0;

}




