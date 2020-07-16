#include <string>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;
typedef char* pstring;


class Clc{
public:
	Clc(){
		std::cout<<"init"<<std::endl;
	}
	Clc(const Clc& clc){
		std::cout<<"copy init"<<std::endl;
	}
	Clc(Clc&& clc){
		std::cout<<"move init"<<std::endl;
	}
	Clc& operator=(const Clc& clc){
		std::cout<<"assign"<<std::endl;
		return *this;
	}
	
};

#if 0
class HasPtr{
public:
	HasPtr(const std::string& s = std::string()):ps(new std::string(s)),i(0){
	
	}
	HasPtr(const HasPtr& p):ps(new std::string(*p.ps)),i(p.i){
	}

	HasPtr& operator=(const HasPtr& p){
		std::string* pnew=new std::string(*p.ps);
		delete ps;
		ps =  pnew;
		i=p.i;
		return *this;
	}

    ~HasPtr(){
		delete ps;
	}

private:
	std::string * ps;
	int i;
};
#endif


class HasPtr{
public:
	HasPtr(const std::string& s = std::string()):ps(new std::string(s)),i(0),use(new std::size_t(1)){
	
	}
	HasPtr(const HasPtr& p):ps(new std::string(*p.ps)),i(p.i),use(p.use){
		++(*use);
	}

	HasPtr& operator=(const HasPtr& rhs){
		++(*rhs.use); //递增右侧运算对象的引用计数
		if(--(*use) ==0){//然后递减本对象的引用计数
			delete ps;   //如果没有其他用户
			delete use;  //释放本对象分配的成员
		}
		ps = rhs.ps;
		i = rhs.i;
		use=rhs.use;
		return *this;
	}
    ~HasPtr(){
		if(--(*use) ==0){
			delete ps;
			delete use;
		}
	}

private:
	std::string * ps;
	int i;
	std::size_t* use;
};







int main()
{
	Clc clcer1;

	Clc clcer2 = Clc();


	const pstring cstr = nullptr;
	char p = '1';
	//cstr=&p;
	//*cstr=p;
	std::cout<<sizeof(&p)<<std::endl;
	std::cout<<sizeof(vector<int>)<<std::endl;
	std::string s("123456");
	std::cout<<s.length()<<std::endl;
	std::cout<<strlen(s.c_str())<<std::endl;
	std::cout<<stof(s)<<std::endl;	
	
	std::string s2(5,'\0');
	std::cout<<s2.length()<<std::endl;
	std::cout<<strlen(s2.c_str())<<std::endl;
	return 0;
}

