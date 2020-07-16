#include <iostream>
#include <vector>
using namespace std;

void print_vec(const vector<int>& vec){
	vector<int>::const_iterator it ;

	cout<<"print-start ********************\n";
	for(it = vec.begin();it != vec.end();it++)
		cout<<&*it <<" "<<*it<<endl;
	cout<<"print-end   ********************\n";
}


int main(){
	vector<int>vec(3,100);
	print_vec(vec);
	
	vector<int>::iterator it = vec.begin();
	it = vec.insert(it,200);
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
	
	vec.insert(it,2,300);

	print_vec(vec);
	it = vec.begin();
	
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
	
	vector<int> vec2(2,400);
	it = vec.insert(it +2,vec2.begin(),vec2.end());
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
	
	return 0;
}

