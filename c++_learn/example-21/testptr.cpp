#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Blob{
	private:
		int data_ = 0;
	public:
		const static int number = 10;
		enum {MAX_SIZE=20};
		
		Blob(int s_data = 0):data_(s_data){
			cout<<"constructor blob "<<data_<<endl;
		}
		
		Blob(const Blob& s_blob):data_(s_blob.data_){
			cout<<"copy constructor blob"<<endl;
		}
#if 1
		Blob(Blob&& s_blob):data_(s_blob.data_){
			cout<<"move constructor blob"<<endl;
		}
#endif

		~Blob(){
			cout<<"delete blob "<<data_<<endl;
		}

};


#if 0
class StrBlob{
	public:
		typedef std::vector<string>::size_type size_type;
		
		StrBlob():data_(make_shared<vector<string>>()){
		};
		
		StrBlob(initializer_list<string> il):data_(make_shared<vector<string>>(il)){
		};

		size_type size()const{ 
			return data_->size();
		}
		bool empty()const{
			return data_->empty();
		}
		void push_back(const string& st){
			data_->push_back(st);
		}
		
		void pop_back(){
			data_->pop_back();
		}

		string& front(){
			return data_->front();
		}
		string& back(){
			return data_->back();
		}
	private:
		shared_ptr<vector<string>>data_;
		void check(size_type i,const string &msg)const;
};
#endif


Blob foo(){
	Blob b(4);
	return b;
}

Blob foo1(){
	return Blob(2);
}

void print_test(Blob* p){
	cout<<"call"<<endl;
}

shared_ptr<Blob> make_blob(int p){
	return shared_ptr<Blob>(new Blob(p));
}

//shared_ptr<Blob> make_blob(int p){
//	cout<<"before\n";
//	shared_ptr<Blob> middle_blob=make_shared<Blob>(p);
//	cout<<"after\n";
//	return middle_blob;
//}


void my_own_deleter(string* p){
	cout<<"delete  "<<*p<<endl;
	delete p;

}


int main(){
#if 1
	{
		shared_ptr<Blob> p1 = make_shared<Blob>(40);	
		shared_ptr<Blob> p2 = make_shared<Blob>(42);
		p1 = p2;
		cout<<"assign-value ptr testing end\n";
		cout<<endl;

		shared_ptr<Blob>p3(p2);
		Blob* tmp_blob_ptr = new Blob;
		shared_ptr<Blob>p4(tmp_blob_ptr);
		p1.reset(new Blob);
		
		cout<<p3.use_count()<<" " <<p2.use_count()<<" " <<p1.use_count()<<endl;
		cout<<"block end\n";
		
		Blob tmp_blob=Blob(4);
		Blob blob1(tmp_blob);

	}
	cout<<"part-1 Done.\n";
	cout<<endl;
	cout<<Blob::MAX_SIZE<< " "<<Blob::number<<endl;
#endif
	
	{
		Blob blob_copy = foo();
//	Blob blob_copy = foo1();
	}

	cout<<endl;
	cout<<"shared_ptr\n";
	cout<<endl;
	{
		vector<shared_ptr<Blob>> blob_ptr_vec;
		cout<<"first time\n";
		
		{
			shared_ptr<Blob> ptr_blob1  = make_blob(43);
			shared_ptr<Blob> ptr_blob2  = make_blob(33);
		
			cout<<"i ,use_cout(): "<<1<<" "<<ptr_blob1.use_count()<<endl;
			cout<<"i ,use_cout(): "<<2<<" "<<ptr_blob2.use_count()<<endl;
			
			blob_ptr_vec.push_back(ptr_blob1);
			blob_ptr_vec.push_back(ptr_blob2);
			cout<<"i ,use_cout(): "<<1<<" "<<ptr_blob1.use_count()<<endl;
			cout<<"i ,use_cout(): "<<2<<" "<<ptr_blob2.use_count()<<endl;
		}

		for(int i = 0;i<2;++i){
			Blob* p_blob = blob_ptr_vec[i].get();
			print_test(p_blob);
			//shared_ptr<Blob> bad_ptr_blob(p_blob);
			shared_ptr<Blob> bad_ptr_blob(blob_ptr_vec[i]);
			cout<<"i ,use_cout(): "<<i<<" "<<blob_ptr_vec[i].use_count()<<endl;
		}
	
		cout<<"second time\n";
		vector<shared_ptr<Blob>> blob_ptr_vec1 = blob_ptr_vec;
		
		for(int i = 0;i<2;++i){
			cout<<"i ,use_cout(): "<<i<<" "<<blob_ptr_vec[i].use_count()<<endl;
		}
	}

	{
		shared_ptr<string> pNico4;
		pNico4.reset(new string("nico"),my_own_deleter);
		(*pNico4)[0]='N';
		cout<<*pNico4<<endl;
		pNico4->replace(0,1,"J");
		cout<<*pNico4<<endl;
	}
	
	{
		unique_ptr<string[]>up(new string[10]{"hello","word"});//
		unique_ptr<int>int_ptr(new int(5));//
		
		cout<<"get index 0 value: "<<up[0]<<" "<<*int_ptr<<endl;
	
		unique_ptr<string> pTrivial;
		unique_ptr<string> pTrivial1(new string("hxlx"));
		//pTrivial = unique_ptr<string>(new string("good"));
		pTrivial.reset(pTrivial1.release());
		
		cout<<*pTrivial<<endl;
		//pTrivial = pTrivial1;
		//unique_ptr<string> pTrivial2(pTrivial1);


	}

	cout<<"Done.\n";
	return 0;
}
