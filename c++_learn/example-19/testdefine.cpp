#include <iostream>
#include <vector>
using namespace std;

#define Peard(type) \
	type Peard##type(type a,type b){ \
		return a + b; \
	} \

#define Teard(name); \
	class Teard##name{ \
	private:       \
		int a_ = 0; \
	public:        \
		void set(int a ){ a_=a ;} \
		int get(){return a_;} \
}; \

Peard(int);

Teard(m);

template <typename T>
class Blob{
	private:
		T data_;
	public:
		Blob(const T& m_data):data_(m_data){
			
		}
		Blob(){
		}
		const T& get_data(){
			return data_;
		}
};

void PRINT(int a){
	std::cout<<a<<"   " <<&a<<std::endl;
}

void PRINT_REF(int& a){
	std::cout<<a<<"   " <<&a<<std::endl;
}

int main(){
	Blob<int> test_blob(4);
	std::cout<<Peardint(2,3)<<std::endl;
	Teardm m;
	std::cout<<m.get()<<std::endl;
	vector<int> test_vec;
	for(int i = 0;i<5;++i){
		int tmp = 5;
		test_vec.push_back(tmp);
		test_vec[i] = 6;
		cout<<tmp<< " "<<test_vec[i]<<endl;
	}
	int a = 10;
	std::cout<<a<<"   " <<&a<<std::endl;
	vector<int> test_ivec;
	int  c = 1;
	for(int i = 0;i<5;++i){
		c = i;
		test_ivec.push_back(c);
	}
	for(int i = 0;i<5;++i){
		cout<<c<<"  "<<(void*)&c<<" "<<test_ivec[i]<<" " <<(void*)&(test_ivec[i])<<endl;
	}
	PRINT(a);
	PRINT_REF(a);
	return 0;
}

