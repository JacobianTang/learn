#include <iostream>
#include "support.h"
extern double warming;

//void update(double dt);
//void local();

using std::cout;

void update(double dt){
	extern double warming;
	warming += dt;
	cout<< "Updating global warming to " <<warming;
	cout<<" degrees.\n";
}

void local(){
	double warming =0.8;
	cout<<"local warming = "<< warming <<" degrees.\n";
	cout<<"but global warming ="<<warming;
	cout<<" degrees.\n";
}

