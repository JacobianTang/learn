#include <new>
#include <vector>
#include <string>
#include <iostream>
#include <memory>
using namespace std;


class StrVec{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(const StrVec& s){
		auto newdata = alloc_n_copy(s.begin(),s.end());
		elements = newdata.first;
		first_free = cap =newdata.second;
	}

	StrVec& operator=(const StrVec& rhs){
		auto data = alloc_n_copy(rhs.begin(),rhs.end());
		free();
		elements = data.first;
		first_free = cap=data.second;
		return *this;
	}

	~StrVec(){
		free();
	}
	void push_back(const string& s);
	size_t size(){ return first_free-elements;}
	size_t capacity() { return cap - elements;}
	string* begin()const {return elements;}
	string* end()const{return first_free;}
private:
	
	static std::allocator<string> alloc; //分配元素

	void chk_n_alloc(){
		if(size()==capacity()){
			reallocate();
		}
	}
	
	std::pair<string* ,string*>alloc_n_copy(const string*,const string*);

	void free();
	void reallocate();
	string* elements;
	string* first_free;
	string* cap;

};


void StrVec::reallocate(){
	auto newcapacity = size()?2*size():1;
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata; //指向新数组找那个下一个空闲位置
	auto elem = elements; //指向旧数组中下一个元素
	//将数据从就内存移动到新内存
	for(size_t i = 0;i !=size();++i){
		//使用移动构造，而不使用复制构造，提升速度
		alloc.construct(dest++,std::move(*elem++));
	}
	//一旦移动完元素，释放就空间
	free();
	elements = newdata;
	first_free=dest;
	cap=elements + newcapacity;
}

void StrVec::push_back(const string& s){
	//调用chk_n_alloc()确保有足够的内存
	chk_n_alloc();
	
	//当我们使用allocator分配内存时，必须记住内存时未构造的
	//为了使用原始内存，调用construct，在此内存中构造一个对象。
	//这里使用的string的拷贝构造函数
	alloc.construct(first_free++,s);

}

//alloc_n_copy会分配足够的内存来保存给定范围的元素，并将这些元素拷贝
//到新分配的内存中。
//此函数返回一个pair，两个指针分配指向分配新空间的开始位置和拷贝的尾后的位置
pair<string* ,string*>
StrVec::alloc_n_copy(const string* b,const string* e){
	auto data = alloc.allocate(e-b);
	return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free(){
	if(elements){
		//destroy函数运行string的析构函数，释放string自己分配的内存空间
		for(auto p=first_free;p!=elements;)
			alloc.destroy(--p);
		//调用deallocate来释放本StrVec对象分配的内存空间。
		alloc.deallocate(elements,cap-elements);
	}

}

int main(){
	StrVec strvec_;
	vector<string> p = {"1","2","3","4","5"};
	std::cout<<p.end()-p.begin()<<std::endl;
}
