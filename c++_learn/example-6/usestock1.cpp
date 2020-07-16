#include <iostream>
#include "stock00.h"

int main(){
	{
		using std::cout;
		cout<<"Using constroctors to create new object\n";
		Stock stock1("NamoSmart",12,20.0);//syntax 1
		stock1.show();
		Stock stock2=Stock("Boffo Objects",2,2.0);//syntax 2
		stock2.show();

		cout<<"Assigning stock1 to stock2:\n";
		stock2=stock1;
		cout<<"Listing stock1 and stock2:\n";
		stock1.show();
		stock2.show();
		cout <<"Using a constructor to rest an object\n";
		stock1=Stock("Nifty Foods",10,50.0);//temp oject;
		cout <<"Reviesd stock1:\n";
		stock1.show();
		cout<<"Done\n";
	}
	return 0;
}
