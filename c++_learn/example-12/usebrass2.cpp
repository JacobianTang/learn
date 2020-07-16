#include <iostream>
#include <string>
#include "brass.h"

const int CLIENTS = 4;

int main(){
	using std::cout;
	using std::endl;
	short things[]={1,2,3,4};
	cout<<"num_things: "<<sizeof(things)<< " ,"<<sizeof(short)<<", "<<sizeof(things)/sizeof(short)<<endl;
	Brass* p_clients[CLIENTS];

	p_clients[0]=new Brass("Harry Fishong",112233,1500);
	p_clients[1]=new BrassPlus("Dinah Otternoe",121213,1800,350,0.12);
	p_clients[2]=new BrassPlus("Brenda Birdherd",212118,5200,800,0.10);
	p_clients[3]=new Brass("Tim Turtletop",233255,688);
	for(int i=0;i<CLIENTS;++i){
		p_clients[i]->ViewAcct();
		cout<<endl;
	}
	for(int i=0;i<CLIENTS;++i){
		delete p_clients[i];
	}
	cout<<"done\n";
	return 0;
}

