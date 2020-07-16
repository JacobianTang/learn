#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <memory>

using namespace std;

template<typename T>
class Singleton{
	public:
		static T& get_instance(){
			static T instance;
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
		DerivedSingle()=default;
};


int main(){

	DerivedSingle& instance1 = DerivedSingle::get_instance();

	DerivedSingle& instance2 = DerivedSingle::get_instance();


}

