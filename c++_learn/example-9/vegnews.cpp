#include<iostream>
using std::cout;
#include "strngbad.h"

void callme1(StringBad &);
void callme2(StringBad);


int main(){
	using std::endl;
	{
		cout<<"Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce prey");
		StringBad sports("Spinach Leaves Bow1 for Dollors");
		cout <<"headline1: "<<headline1<<endl;
		cout<<"headlien2: "<<headline2<<endl;
		cout<<"Sports: "<<sports<<endl;
		
		int num_1= headline1.HowMany();
		int num_2=StringBad::HowMany();
		cout<<"num_1 :"<<num_1<<" num_2: "<<num_2<<endl;
		callme1(headline1);
		cout <<"headline1: "<<headline2<<endl;
		callme2(headline2);
		cout<<"headlien2: "<<headline2<<endl;
		
		cout<<"Initialize one object to another:\n";
		StringBad sailor = sports;
		cout<<"sailor: "<<sailor<<endl;
		cout <<"Assign one object to another:\n";
		StringBad knot;
		knot=headline1;
		cout<<"knot: "<<knot<<endl;
		cout<<"Exiting the block.\n";
	}
	cout<<"End of main()\n";
}



void callme1(StringBad& rsb){
	cout<<"String passed by reference: \n";
	cout<< "   \""<<rsb<<"\"";
}

void callme2(StringBad sb){
	cout<<"String passed by value: \n";
	cout<< "   \""<<sb<<"\"";
}
