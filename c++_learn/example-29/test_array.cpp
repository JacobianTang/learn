#include <iostream>
#include <array>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


template <typename T>
void PRINT_ELEMENTS(T & a){
	for(const auto& elem:a){
		cout<<elem << " " ;
	}
	cout<<endl;
}


int main(){

	array<int ,10> a={11,22,33,44};
	sort(a.begin(),a.end(),std::less<int>());
	
	PRINT_ELEMENTS(a);
	vector<int> c(a.begin(),a.end());
	
	PRINT_ELEMENTS(c);
	
	PRINT_ELEMENTS(a);

	a.back()=99999;

	a[a.size()-2]=42;

	PRINT_ELEMENTS(a);
	
	cout<<"sum: "
		<<accumulate(a.begin(),a.end(),1,std::plus<int>())
		<<accumulate(a.begin(),a.end(),1,[](int& a,int & b){ return a*b;})
		<<endl;
	
	transform(a.begin(),a.end(),a.begin(),negate<int>());
	
	PRINT_ELEMENTS(a);

}
