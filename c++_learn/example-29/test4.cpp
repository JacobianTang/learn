#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <stack>
#include <cstring>
using namespace std;

struct clc{
	private:
		int a ;
		int b ;
	public:
		clc(){
			std::cout<<"init"<<endl;
		}
	
		clc(const clc& A){
			std::cout<<"const copy"<<endl;
		}	
		
		//clc(clc& A){
		//	std::cout<<"copy"<<endl;
		//}	

		clc(clc&& A){
			std::cout<<"move"<<endl;
		}
		
		~clc(){
			std::cout<<"del"<<endl;
		}
};

template<typename T>
void print_(const T& t){
	for(const auto& elem:t){
		cout<<elem<<" "	;
	}
	cout<<endl;
}

template<typename T>
void create_copy(T&& x){
	//clc tmp(x);
	clc tmp1(std::forward<T>(x));
}

template<class...Args>
void create_copy_(Args&&... args){
	clc tmp(std::forward<Args>(args)...);
}


template<typename T>
void create_copy(const T& t){
	clc tmp(t);
}


int main(){
	vector<int> vec_ = {65,32,68,19,24,31,26,21,16,13,50};
	print_(vec_);

	vector<clc> clc_vec_;
	clc_vec_.reserve(5);
	for(int i = 0;i<5;++i){
		clc tmp;
		//create_copy(tmp);
		create_copy(tmp);
		//clc copy_tmp = tmp;
		//clc_vec_.push_back(tmp);
		//clc_vec_.push_back(std::move(tmp));
		cout<<"next ----------->"<<endl;
	}
}

