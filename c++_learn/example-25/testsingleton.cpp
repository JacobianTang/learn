#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <memory>

using namespace std;

class EasySingleton{
	public:
		~EasySingleton(){
			cout<<"Easy destructor called\n";
		}

		static EasySingleton& get_instance(){
			static EasySingleton instance;
			return instance;
		}

		void use()const{
			cout<<"in use"<<endl;
		}

	private:
		EasySingleton(){
			cout<<"Easy constructor called\n";
		}
		
		EasySingleton(const EasySingleton&)=delete;
		EasySingleton& operator=(const EasySingleton&)=delete;
};

class SafeSingleton{
	public:
		typedef shared_ptr<SafeSingleton> ptr;
		
		~SafeSingleton(){
			cout<<"Safe destructor called\n";
		}

		static ptr get_instance(){
			//double check lock
			if(m_instance_ptr == NULL){
				lock_guard<mutex> lg(m_mutex);
				if(m_instance_ptr==NULL){
					m_instance_ptr.reset(new SafeSingleton);
				}
			}
			return m_instance_ptr;
		}

		void use()const{
			cout<<"in use"<<endl;
		}

	private:
		SafeSingleton(){
			cout<<"Safe constructor called\n";
		}
		SafeSingleton(const SafeSingleton&)=delete;
		SafeSingleton& operator=(const SafeSingleton&)=delete;
		
		static ptr  m_instance_ptr;
		static mutex m_mutex;
};
//static initialization
SafeSingleton::ptr SafeSingleton::m_instance_ptr = nullptr;
std::mutex SafeSingleton::m_mutex;


class Singleton{
	private:
		Singleton(){
			cout<<"constructor called\n";
		}
		//copy
		Singleton(const Singleton&)=delete;
		//assign
		Singleton& operator=(const Singleton&)=delete;
		static Singleton* m_instance_ptr;
	public:
		~Singleton(){
			cout<<"destructor called\n";
		}

		static Singleton* get_instance(){
			if(m_instance_ptr==NULL){
				m_instance_ptr = new Singleton;
			}
			return m_instance_ptr;
		}

		void use()const{
			cout<<"in use"<<endl;
		}

};

Singleton* Singleton::m_instance_ptr=nullptr;

int main(){
	{
		Singleton* instance = Singleton::get_instance();
		delete instance;
	}


	{
		SafeSingleton::ptr instance = SafeSingleton::get_instance();
		SafeSingleton::ptr instance2 = SafeSingleton::get_instance();
		cout<<instance2.use_count()<<endl;
	}

	{
		EasySingleton& instance = EasySingleton::get_instance();
		EasySingleton& instance2 = EasySingleton::get_instance();
		
		//EasySingleton instance = EasySingleton::get_instance();//invalid
		//EasySingleton instance2 = EasySingleton::get_instance();//invalid
	}

}

