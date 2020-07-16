#include <memory>
#include <iostream>
using namespace std;

class CallBack{
	public:
		virtual ~CallBack(){};
		virtual void func1() = 0;
		virtual void func2() = 0;
};


class BeInvoked:public CallBack{
	public:
		virtual void func1(){
			cout<<"BeInvoked class func1 be called"<<endl;

		};
		virtual void func2(){
			cout<<"BeInvoked class func2 be called"<<endl;
		};
};

class Invoke {
	private:
	    CallBack* callback_;
	public:
	   Invoke(){};
	   ~Invoke(){};
	    void set_callback(CallBack*  par_callback){
	         callback_ = par_callback;
	    };
	    
	    void run(){
	        if(callback_ != nullptr){
	           callback_-> func1();
	           callback_-> func2();
	        }
	    }
};

int main(){
	Invoke invoke_instance;
	CallBack* tmp = new BeInvoked();
	invoke_instance.set_callback(tmp);
	invoke_instance.run();
	delete tmp;

}
