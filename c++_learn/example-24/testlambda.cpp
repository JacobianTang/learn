#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	auto plus_ten=[](int  i){
			return i + 10;
	};
	
	auto plus_ten_times_two=[](int i){
			return (i +10)*2;
	};

	cout<<plus_ten(10)<<endl;

	cout<<plus_ten_times_two(10)<<endl;


	vector<int> coll = {1,2,3,4,5,6,7,8};
	long sum = 0;
	for_each(coll.begin(),coll.end(),[&sum](int elem){
				sum += elem;
			});
	double mv = static_cast<double>(sum)/static_cast<double>(coll.size());
	
	auto it = find_if(coll.begin(),coll.end(),[](int elem){ return elem==2;});
	
	cout<<*it<<endl;

	cout<<"mean value "<<mv<<endl;

}
