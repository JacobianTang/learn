#include <iostream>
#include <string>
struct Node{
	int val;
	struct Node* next;
	std::string name;
};

int main(){
	using namespace std;
	double wages[3]={10000.0,20000.0,30000.0};
	short stacks[3]={3,2,1};
	
	struct Node* next;
	cout<<"sizeof(Node) "<<sizeof(Node)<<" "<<sizeof(next)<<" " <<sizeof(int)<<endl;
	double* pw = wages;
	short* ps = &stacks[0];

	//with array element
	cout<<"pw= "<<pw<<", *pw "<<*pw<<"\n\n";
	pw =pw +1;
	cout<<"add 1 to the pw pointer:\n";
	cout<<"pw= "<<ps<<", *pw "<<*pw<<"\n\n";
	
	cout<<"ps= "<<ps<<", *ps "<<*ps<<"\n\n";
	cout<<"add 1 to the ps pointer:\n";
	ps =ps +1;
	cout<<"ps= "<<ps<<", *ps "<<*ps<<"\n\n";

	cout<<"Access two elements with array notation\n";
	cout<<"stacks[0]= "<<stacks[0]
		<<" ,stacks[1]= "<<stacks[1]<<endl;

	cout<<"*stacks= "<<*stacks
		<<" ,*(stacks + 1)= "<<*(stacks + 1)<<endl;
	
	cout <<sizeof(wages)<<" = size of wages array\n";
	cout<<sizeof(pw) <<" = size of pw pointer\n";
	return 0;

}
