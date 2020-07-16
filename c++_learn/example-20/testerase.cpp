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
	vector<int>vec={500,400,300,100,100,100};
	print_vec(vec);
	
	vector<int> blank_vec;
	vec.swap(blank_vec);
	print_vec(blank_vec);
	return 1;
	cout<<"start testing\n";

	vector<int>::iterator it = vec.begin();
	
	it = vec.erase(it);
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;

	it = vec.erase(it+1);
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
	
	it = vec.begin();
	it = vec.erase(it+1,it+3);
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;


	it = vec.begin();
	it = vec.erase(it,it+2);
	print_vec(vec);
	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
		

//	vec.insert(it,2,300);
//
//	print_vec(vec);
//	it = vec.begin();
//	
//	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
//	
//	vector<int> vec2(2,400);
//	it = vec.insert(it +2,vec2.begin(),vec2.end());
//	print_vec(vec);
//	cout<<&*it <<" "<<*it<<" "<<&vec[0]<<" "<<vec[0] <<endl;
	
	return 0;
}

