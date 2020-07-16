
#include <iostream>
#include <thread>

using namespace std;


class callback{
	//protected:
	public:	
		virtual void add(int a,int b)=0;
		virtual void sub(int a,int b)=0;

	//friend class Invoke;
};


class Invoke
{
	public:
		Invoke(callback* p){
			pcall_ = p;
		}
		
		Invoke(){
		
		}
		
		void set_callback(callback* p){
			pcall_ = p;
		}
		
		void call4fun(){
			pcall_->add(1,3);
			pcall_->sub(1,3);
		}
	private:
		callback* pcall_;
};

class CMath:public callback
{
private:
	//Invoke invoker;
public:
	CMath(){
		//invoker  = new Invoke(this);
		//invoker.set_callback(this);
	}
    
	~CMath(){
		//delete invoker;
	}
    
	virtual void add(int a, int b)
    {
        cout << a << "+" << b << "=" << a + b << endl;
    }
    
	virtual void sub(int a, int b)
    {
        cout << a << "-" << b << "=" << a - b << endl;
    }

	void invoke(){
		//invoker->callback4fun();	
		//invoker.call4fun();	
		Invoke caller;
		caller.set_callback(this);
		caller.call4fun();
	}
};

int main()
{
	CMath cmather;
	cmather.invoke();
	return 0;
}

