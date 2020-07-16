#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template<class Class,typename T,typename P>
class SingularCallBack{
	public:
		typedef T (Class::*Method)(P);

		SingularCallBack(Class* _class_instance,Method _method){
			class_instance_  = _class_instance;
			method_ = _method;
		}

		T operator()(P parameter){
			return (class_instance_->*method_)(parameter);
		}

		T execute(P parameter){
			return operator()(parameter);
		}

	private:
		Class* class_instance_;
		Method  method_;
};

class A{
	public:
		void output(){
		 cout<<"I am class A:D"<<endl;	
		}

};


class B{
	public:
		bool methodB(A a){
			a.output();
			return true;
		}

};


class AClass{
	public:
		AClass(unsigned int _id):id_(_id){};
		~AClass(){};
	
		bool AMethod(string str){
			cout<<"AClass["<<id_<<"]:"<<str<<endl;
			return true;
		}

	private:
		unsigned int id_;

};




template class SingularCallBack<AClass,bool,string>;
int main(){
	A a;
	B b;
	SingularCallBack<B,bool,A>*cb;

	cb = new SingularCallBack<B,bool,A>(&b,&B::methodB);
	
	//if((*cb)(a)){
	if(cb->execute(a)){
		cout<<"CallBack Fired Sucessfully!"<<endl;
	}else{
		cout<<"CallBack Fired UnSucessfully!"<<endl;
	}

	typedef SingularCallBack<AClass,bool,string>ACallBack;

	vector<ACallBack> callback_list;
	AClass a1(1);
	AClass a2(2);
	AClass a3(3);
	callback_list.push_back(ACallBack(&a1,&AClass::AMethod));
	callback_list.push_back(ACallBack(&a2,&AClass::AMethod));
	callback_list.push_back(ACallBack(&a2,&AClass::AMethod));
	for(int i = 0;i<callback_list.size();++i){
		callback_list[i]("abc");
		callback_list[i].execute("abc");
	}


}
