#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

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


class Layer{
	public:
		Layer(){};
		virtual ~Layer(){
			cout<<"destructor Layer"<<endl;
		};
		void forward(){
			forward_cpu();
		}
		
		void backward(){
			backward_cpu();
		}
		void update(){
			update_cpu();
		}
	protected:
		virtual void forward_cpu()=0;
		virtual void backward_cpu()=0;
	    virtual void update_cpu()=0;	
//		virtual void forward_cpu(){
//			cout<<"base Layer forward_cpu()"<<endl;
//		};
//		virtual void backward_cpu(){
//			cout<<"base Layer backward_cpu()"<<endl;
//		}

};

class MaxpoolLayer:public Layer{
	public:
		MaxpoolLayer(){};
		virtual ~MaxpoolLayer(){
			cout<<"destructor MaxpoolLayer"<<endl;
	    }
	protected:

		virtual void forward_cpu(){
			cout<<"MaxpoolLayer forward_cpu()"<<endl;
		}	
		
		virtual void update_cpu(){
			cout<<"MaxpoolLayer update()"<<endl;

		}
		virtual void backward_cpu(){
			cout<<"MaxpoolLayer backward_cpu()"<<endl;

		}
};

class ConvLayer:public Layer{
	public:
		ConvLayer(){};
		virtual ~ConvLayer(){
			cout<<"destructor ConvLayer"<<endl;
		}
	protected:

		virtual void forward_cpu(){
			cout<<"ConvLayer forward_cpu()"<<endl;
		}	
		
		virtual void update_cpu(){
			cout<<"ConvLayer update()"<<endl;

		}
		virtual void backward_cpu(){
			cout<<"ConvLayer backward_cpu()"<<endl;

		}
};



class ConcateLayer:public Layer{
	public:
		ConcateLayer(){};
		virtual ~ConcateLayer(){
			cout<<"destructor ConcateLayer"<<endl;
		}
	protected:

		virtual void forward_cpu(){
			cout<<"ConcateLayer forward_cpu()"<<endl;
		}	
		
		virtual void backward_cpu(){
			cout<<"ConcateLayer backward_cpu()"<<endl;

		}
		virtual void update_cpu(){
			cout<<"ConcateLayer update()"<<endl;

		}
};





typedef shared_ptr<Layer> (*Creator)();

map<string,Creator> CreatorRegistry;

class layer_register{
	public:
		layer_register(string type,Creator creator){
			CreatorRegistry[type]=creator;
		};
};

#define REGISTRY_LAYER_CREATOR(type,creator)\
static layer_register g_regiser##type(#type,creator);\
 


#define REGISTRY_LAYER_CLASS(type) \
shared_ptr<Layer> Create##type##Layer()\
{                                       \
	return shared_ptr<Layer>(new type##Layer());\
}                                                \
REGISTRY_LAYER_CREATOR(type,Create##type##Layer)  


REGISTRY_LAYER_CLASS(Concate);
REGISTRY_LAYER_CLASS(Conv);
REGISTRY_LAYER_CLASS(Maxpool);


#if 0
shared_ptr<Layer> CreateConcateLayer(){
	return shared_ptr<Layer>(new ConcateLayer());
}

shared_ptr<Layer> CreateConvLayer(){
	return shared_ptr<Layer>(new ConvLayer());

}

shared_ptr<Layer> CreateMaxpoolLayer(){
	return shared_ptr<Layer>(new MaxpoolLayer());
}
#endif



int main(){
	{
		
#if 0
		map<string,Creator> CreatorRegistry;

		CreatorRegistry["Concate"]=CreateConcateLayer;
		CreatorRegistry["Conv"]=CreateConvLayer;
		CreatorRegistry["Maxpool"]=CreateMaxpoolLayer;
#endif	
		vector<string> layer_names_={"Concate","Conv","Maxpool"};
		vector< shared_ptr<Layer> >layers_;
		for(int i =0;i<layer_names_.size();i++){
			layers_.push_back(CreatorRegistry[layer_names_[i]]());
		}
	//	layers_.push_back(shared_ptr<Layer>(new ConcateLayer()));
	//	layers_.push_back(shared_ptr<Layer>(new ConvLayer()));
	//	layers_.push_back(shared_ptr<Layer>(new MaxpoolLayer()));
		for(int i =0;i<layers_.size();i++){
			layers_[i]->forward();
		}
		cout<<"  "<<endl;	
		for(int i = layers_.size()-1;i>=0;i--){
			layers_[i]->backward();
			layers_[i]->update();
		}
		cout<<"  "<<endl;	
	}

	{	
		DerivedSingle& instance1 = DerivedSingle::get_instance();
		DerivedSingle& instance2 = DerivedSingle::get_instance();

	}

//	std::shared_ptr<int> p;
//	p = make_shared<int>(43);
//	cout<<p.use_count()<<"  "<<*p<<endl;
}
