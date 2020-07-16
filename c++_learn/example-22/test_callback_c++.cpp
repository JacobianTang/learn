#include<iostream>
#include<cstdlib>

using namespace std;

class CallBack{
	public:
		virtual void set_finance_result(int result) =0;
};


class Finance{
	public:
		Finance(CallBack* m_callback):callback_(m_callback){
			cout<<"finance costructor"<<endl;
		}
		~Finance(){
			cout<<"finance destructor"<<endl;
		}
		
	    void CaculateFinance(int *a ,int n){
			int result = 0;
			for(int i = 0;i<n;i++){
				result += a[i];
			}
			
			if(callback_ != NULL){
				cout<<"result: "<<result<<endl;
				callback_->set_finance_result(result);
			}
		}
	private:
		CallBack* callback_;
};


class Boss:public CallBack{
	public:
		Boss(){
			finance_ = new Finance(this);
			cout<<"boss constructor"<<endl;
		}
		~Boss(){
			delete finance_;
			cout<<"boss constructor"<<endl;
		}

		void read_finance(int * array,int n){
			cout<<"boss read_finance"<<endl;
			finance_->CaculateFinance(array,n);
		}
		
		void set_finance_result(int result){
			cout<<"caculate result:"<<result<<endl;
			result_ = result;
		}
		int& get_finance_result(){
			return result_;
		}
	private:
		Finance* finance_;
		int result_ = 0;
		
};


//1.老板想查看财务（调用自己的函数，函数在boss内）
//2.通知财务，我要查看报表(进行计算的过程，函数在财务类里）
//3.财务算好之后，返回给老板（回调的函数在boss内部）
//也就是回调就是把不需要自己处理的东西放到别的类去，然后等其处理完毕之后，在返回
//给调用类。


int main(){
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	Boss boss;
	cout<<"get_finance_result :"<<boss.get_finance_result()<<endl;
	
	boss.read_finance(array,10);
	cout<<"get_finance_result :"<<boss.get_finance_result()<<endl;

	return 0;
}



