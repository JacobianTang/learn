#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
class Singleton{
	public:
		static T& get_instance(){
			static T instance;
			return instance;
		}
		static T& get_instance(int i_data){
			static T instance(i_data);
			return instance;
		}
  
		virtual ~Singleton(){
			cout<<"destructor called!"<<endl;
		}

		Singleton(const Singleton& )=delete;
		Singleton& operator=(const Singleton&)=delete;
	protected:
		Singleton(){
			cout<<"constructor called!\n"<<endl;
		}
};

//Example
//1.friend class declaration is requiered!
//2.constructor should be private
//

class DerivedSingle:public Singleton<DerivedSingle>{
	///must be friend class
	//base class can access derived class constructor /destructor
	friend class Singleton<DerivedSingle>;

	public:
		DerivedSingle(const DerivedSingle& )=delete;
		DerivedSingle& operator=(const DerivedSingle&)=delete;
	private:
        int data_ ;
		DerivedSingle()=default; 
        DerivedSingle(int i_data){
            data_ = i_data;
        };
};







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


shared_ptr<BaseModel> createBNet(){
	return shared_ptr<BaseModel>(new BNet());
}

shared_ptr<BaseModel> createANet(){
	return shared_ptr<BaseModel>(new ANet());
}

int main(){


	{	
		DerivedSingle& instance1 = DerivedSingle::get_instance();
		DerivedSingle& instance2 = DerivedSingle::get_instance();

	}


	{
		shared_ptr<BaseModel> tmp = createBNet();
		shared_ptr<BaseModel> cp=tmp;
		cout<<tmp.use_count()<<endl;
		cout<<"-----------------------"<<endl;

	}
		cout<<"-----------------------"<<endl;

	{
//		BaseModel* temp_ptr = new ANet();
//		BaseModel* temp;
//		shared_ptr<BaseModel> p;
//		const BaseModel& tmpInstance = ANet();
		//vector< BaseModel > pModelVec_;
		vector< shared_ptr<BaseModel> > p_vec_; 
		p_vec_.push_back(shared_ptr<BaseModel>(new ANet()));
		p_vec_.push_back(shared_ptr<BaseModel>(new BNet()));
		cout<<"------------------\n";	
		for(int i =0;i<2;i++){
			p_vec_[i]->preprocess();
			p_vec_[i]->predict();
			p_vec_[i]->post();
		}
	}
}
