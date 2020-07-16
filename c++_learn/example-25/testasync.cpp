#include <vector>
#include <future>
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

class Add{
	private:
		int count_ = 0;
		int sum_ = 0;
		shared_ptr<thread> p_;
	public:
		void sum(const vector<int> & input_vec){
			cout<<"start\n"<<endl;
			for(int i =0;i<input_vec.size();++i){
				sum_ += input_vec[i];
			}
			count_ = input_vec.size();
			cout<<"count_: "<<count_<<"  sum_: "<<sum_<<endl;
			cout<<"end\n"<<endl;
		}

		void start_cal(const vector<int> & input_vec){
			p_.reset(new thread(&Add::sum,this,input_vec));
			cout<<p_->joinable()<<endl;
			p_->join();
			cout<<p_->joinable()<<endl;
		}

		const int& get_sum(){
			return sum_;
		}
		const int& get_count(){
			return count_;
		}

		~Add(){
		}

};

int main(){
	vector<int> input_vec={1,2,3,4,5,6,7,8,9,10};
#if 1
	shared_ptr<thread> p;
	Add A;
	p.reset(new thread(&Add::sum,&A,input_vec));

	if(p){
		cout<<"ok\n";
	}
	p->join();
	if(p){
		cout<<"ok 2\n";
	}
#endif

#if 0
	Add A;
	A.start_cal(input_vec);
#endif
	cout<<"sum_result: "<<A.get_sum()<< " "<<A.get_count()<<endl; 
}

