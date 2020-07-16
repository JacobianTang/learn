#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class BaseModel{
	private:
		int data_;

	public:
		BaseModel():data_(0){
			cout<<"BaseModel NET"<<endl;
		};
		
		virtual ~BaseModel(){
			cout<<"del BaseModel NET"<<endl;
			
		}
		
		//virtual int preprocess();
		//virtual int post();
		
		virtual int preprocess()=0;
		virtual int post()=0;

		int predict(){
			cout<<"predicting: " <<endl;
			return 1;
		}
};


class BNet:public BaseModel{
	private:
		const int b_data_;
	public:
		BNet():BaseModel(),b_data_(1){
			cout<<"B NET"<<endl;
		};

		~BNet(){
			cout<<"del B NET"<<endl;
			
		}
		
		virtual int preprocess(){
			cout<<"B Net Proprocess"<<endl;	
			return 0;
		};

		virtual int post(){
			cout<<"B Net Post"<<endl;	
			return 0;	
		};

};	

class ANet:public BaseModel{
	private:
		int a_data_;
		char* ptr;
	public:
		ANet():BaseModel(),a_data_(0){
			cout<<"A NET"<<endl;
		};
		
		~ANet(){
			cout<<"del A NET"<<endl;
			
		}

		virtual int preprocess(){
			cout<<"A Net Proprocess"<<endl;	
			return 0;
		};

		virtual int post(){
			cout<<"A Net Post"<<endl;	
			return 0;
		};
};	

int main(){
	{
		BaseModel* tmp = new ANet();
	
		delete tmp;
		cout<<"----------------"<<endl;	
		shared_ptr<BaseModel> temp(new ANet);
	}

}
