#include <iostream>
#include <string>
#include <vector>

struct job{
	std::string company;
	float salary;
};

template<typename T>
void print_msg(T begin,T end){
	for(T iter = begin;iter != end;++iter){
		std::cout<<*iter<< "  ";
	}
	std::cout<<std::endl;
}

template<>
void print_msg<std::vector<int>::iterator>(std::vector<int>::iterator begin,
				std::vector<int>::iterator end){
	for(auto iter = begin; iter!= end;++iter){
		std::cout<<*iter<< "  ";
	}
	std::cout<<std::endl;
}

template<typename T>
void print_msg(T container){
	for(auto iter=container.begin();iter != container.end();++iter){
		std::cout<<*iter<< "  ";
	}
	std::cout<<std::endl;
}

template <typename T>
void swap(T& a,T& b);

template void swap(float& a,float& b);
template void swap(int& a,int& b);

template <typename T>
void caffe_add_scalar(const int N,const T alpha,T* X);

template <> void caffe_add_scalar<float>(const int,const float,float*);

//template void swap<float>(float& a,float& b);
//template void swap<int>(int& a,int& b);
//template <> void swap<job>(job& a,job& b);

template <> void swap(job& a,job& b);

template<typename T ,typename U>
void print_array(T* arr,U num);

template void print_array<float,int>(float* ,int);

int main(){
	float farr[3]={1,2,3};
	int arr[3]={1,2,3};
	print_array<float,int>(farr,3);
	int a =0;
	int b = 1;
	std::cout<<a<< " "<<b<<std::endl;
	swap(a,b);
	std::cout<<a<< " "<<b<<std::endl;
	
	float af = 0.0f;
	float bf = 1.0f;
	std::cout<<af<< " "<<bf<<std::endl;
	swap(af,bf);
	std::cout<<af<< " "<<bf<<std::endl;
	
	job ajob={"google",100};
	job bjob={"IBM",110};
	
	std::cout<<ajob.company<< " "<<ajob.salary<<std::endl;
	swap(ajob,bjob);
	std::cout<<ajob.company<< " "<<ajob.salary<<std::endl;
	
	caffe_add_scalar(3,0.4f,farr);
	print_msg(std::begin(farr),std::end(farr));

	std::vector<int> msg(std::begin(arr),std::end(arr));
	print_msg(msg);
	print_msg(msg.begin(),msg.end());
}


template<typename T ,typename U>
void print_array(T* arr,U num){
	for(int i = 0;i<num;++i){
		std::cout<<arr[i]<<std::endl;
	}
}
template <typename T>
void swap(T& a,T& b){
	T temp = a;
	a=b;
	b=temp;
}

template <>
void swap<job>(job& a,job& b)
{
	int _b=4;
	const double & m =_b;
	std::cout<<"job specilization"<<std::endl;
	std::swap(a.company,b.company);
	std::swap(a.salary,b.salary);
}

template <>
void caffe_add_scalar<float>(const int N,const float alpha,float* X){
	for(int  i = 0;i<N;++i){
		X[i] += alpha;
	}
}
