#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"


const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout<<"case study:Bank of heather automatic teller\n";
	cout<<"enter maximum size of queue: ";

	int qs;
	cin>>qs;
	Queue line(qs);

	cout <<"enter the number of simulation hours: ";
	int hours;
	cin>>hours;

	long cyclelimit  = MIN_PER_HR*hours;

	cout<<"enter the aveage number of custormer per hour: ";
	double perhour;
	cin>>perhour;

	double min_per_cust;
	min_per_cust = MIN_PER_HR/perhour;

	Item temp;
	long turnways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	long wait_time = 0;
	long line_wait = 0;

	for(int cycle = 0;cycle <cyclelimit;cycle++){
		if (newcustomer(min_per_cust)){
			if(line.isfull()){
				turnways++;
			}else{
				customers ++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		
		if(wait_time<=0 && !line.isempty()){
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle  - temp.when();
			served ++;
		}
		
		if(wait_time >0){
			wait_time --;
		}
		sum_line += line.queuecount();
	}

	if(customers >0){
		cout <<"customers accepted: " <<customers <<endl;
		cout <<"  customers served: "<<served<<endl;
		cout<<"           turnways: "<<turnways<<endl;
		cout<<"average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<" aveage wait time: "
		     <<(double)line_wait/served<<" minutes\n";
	}else{
		 cout<<"No customers!\n";
	}

	cout<<"done\n";
	return 0;
}



bool newcustomer(double x){
	return (std::rand()*x/RAND_MAX< 1);
}
