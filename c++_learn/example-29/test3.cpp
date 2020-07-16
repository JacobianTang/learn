#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <stack>
#include <cstring>
using namespace std;

struct clc{
	private:
		int a ;
		int b ;
	public:
		clc(){
			std::cout<<"init"<<endl;
		}
	
		clc(const clc& A){
			std::cout<<"copy"<<endl;
		}	
		
		clc(clc&& A){
			std::cout<<"move"<<endl;
		}
		
		~clc(){
			std::cout<<"del"<<endl;
		}
};

template<typename T>
void print_(const T& t){
	for(const auto& elem:t){
		cout<<elem<<" "	;
	}
	cout<<endl;
}



void deepSearch(const vector<int>& vec_){
	int node_num  = vec_.size();
	int* visited=(int*)malloc(node_num *sizeof(int));
	memset(visited,0,node_num*sizeof(int));
	stack<int> visited_vec_;
	///push_back root node
	visited_vec_.push(0);
	cout<<0<<"--->";
	while(visited_vec_.size()>0){	

		int cur_node = visited_vec_.top();
	
		//leaf node 
		if(2*cur_node+1 > node_num-1){
		//	cout<<"leaf node"<<cur_node<<endl;
			visited_vec_.pop();
			continue;
		}
		bool isAllVisited = true;	
		for(int i = 0;i<node_num;++i){
			if(visited[i]==1){
				continue;
			}
			if(i==2*cur_node +1 ||i==2*cur_node+2){
				isAllVisited = false;
				visited_vec_.push(i);
				visited[i]=1;
				cout<<i<<"--->";
				break;
			}
		}
		///all adj-node has be visited
		if(isAllVisited){
			visited_vec_.pop();
		}
	}
	cout<<endl;
	free(visited);
}

void breadthSearch(const vector<int>& vec_){
	int node_num  = vec_.size();
	int* visited=(int*)malloc(node_num *sizeof(int));
	memset(visited,0,node_num*sizeof(int));
	vector<int> visited_vec_;
	///push_back root node
	visited_vec_.push_back(0);
	cout<<0<<"--->";
	for(int i = 0;i<visited_vec_.size();++i){
		int cur_node = visited_vec_[i];
		
		for(int i = 0;i<node_num;++i){
			if(visited[i]==1){
				continue;
			}
			if(i==2*cur_node +1 ||i==2*cur_node+2){
				cout<<i<<"--->";
				visited_vec_.push_back(i);
				visited[i]=1;
			//	print_(visited_vec_);
			}
		}
	}
	std::cout<<endl;	
	free(visited);

}



bool is_binary_tree(vector<int>& vec_,int last=-1){
	const int size = vec_.size();
	//且last是不能取到的位置
	if(last == -1){
		last = size;
	}
	for(int i = 0;i<vec_.size();++i){
		int left_ = 2*i + 1;
		int right_ = 2*i + 2;
		
		///左边的节点idx超过数组长度，说明左边节点不存在，当前节点是叶节点
		if(left_ >= last){
			continue;
		}
		//左边的节点存在，但是右边的节点不存在，说明只存在左节点
		if(right_ >=last){
			right_ = left_;
		}
		if(vec_[i] >= vec_[left_] && vec_[i]>= vec_[right_]){
			
		}else{
			return false;
		}

	}
	return true;
}

int main(){
	vector<int> vec_ = {65,32,68,19,24,31,26,21,16,13,50};
	print_(vec_);

	vector<clc> clc_vec_;
	clc_vec_.reserve(5);
	for(int i = 0;i<5;++i){
		clc tmp;
		//clc copy_tmp = tmp;
		clc_vec_.push_back(tmp);
		//clc_vec_.push_back(std::move(tmp));
		cout<<"next ----------->"<<endl;
	}
#if 0
	breadthSearch(vec_);
	deepSearch(vec_);
	vector<int> heap_vec_;

	for(int i = 0;i<vec_.size();++i)
	{
		int push_value = vec_[i];
		heap_vec_.push_back(push_value);
		int son_idx = heap_vec_.size()-1;
		if(heap_vec_.size() <=1){
			continue;
		}
		while(true){
			int father_idx = (son_idx-1)/2;
			if(son_idx<= 0){
				break;
			}
			if(heap_vec_[father_idx] < heap_vec_[son_idx]){
				swap(heap_vec_[father_idx],heap_vec_[son_idx]);
				print_(heap_vec_);
			}
			son_idx = father_idx;
		}
	}

	cout<<is_binary_tree(heap_vec_)<<endl;
	cout<<"sort"<<endl;
	for(int j = 0;j<heap_vec_.size();++j){
		swap(heap_vec_[0],heap_vec_[heap_vec_.size()- 1 - j ]);
		print_(heap_vec_);
		int father_idx = 0;
		cout<<"begin "<<j<<endl;
		///last can be reached.
		int last = heap_vec_.size() - 1 - (j + 1);
		while(true){
			int left_son_idx  = 2*father_idx +1;
			int right_son_idx = 2*father_idx +2;
			
			if(right_son_idx > last ){
				right_son_idx = left_son_idx;
			}
			int son_idx = left_son_idx;
			
			if(heap_vec_[left_son_idx]> heap_vec_[right_son_idx]){
				son_idx =left_son_idx;
			}else{
				son_idx = right_son_idx;
			}

			if(right_son_idx > last 
				|| left_son_idx >last -1){
				cout<<"done"<<endl;
				cout<<"is_binary_tree: "<<is_binary_tree(heap_vec_,last)<<endl;
				print_(heap_vec_);
				break;
			}
			
			if(heap_vec_[father_idx] < heap_vec_[son_idx]){
				swap(heap_vec_[father_idx] ,heap_vec_[son_idx]);
				cout<<"right "<<father_idx<<" "<<son_idx<<endl;
				father_idx = son_idx;
				print_(heap_vec_);
			}else{
				father_idx = son_idx;
			}
			
		}
		print_(heap_vec_);
		cout<<"end"<<endl;
}
#endif

#if 0
	int i = 0 ;
	while(i <5){
		clc good=clc();
		cout<<(void*)&good<<endl;
		clc bad = good;
		clc bad_1 = std::move(good);
		i++;
	}

	std::deque<int> e;
	for(int i = 0;i<100;++i){
		if(i <50){
			e.push_back(i);
		}else{
			e.push_front(i);
		}
	}


	std::cout<<std::addressof(*e.begin())
			<<" "<<std::addressof(*e.end())
			<<" "<<e.size()
			<<" "<<e.max_size()
			<<std::endl;

	e.erase(e.begin()+3,e.begin()+5);
	std::cout<<std::addressof(*e.begin())
			<<" "<<std::addressof(*e.end())
			<<" "<<e.size()
			<<" "<<e.max_size()
			<<std::endl;
	std::vector<int> c(1);
	c.reserve(10);
	for(int i =0;i<100;++i){
		//c.push_back(i);
		std::vector<int>::iterator p = c.insert(c.begin(),i);
		std::cout<<std::addressof(*c.begin())
				<<" "<<std::addressof(*p)
				<<" "<<std::addressof(*c.end())
				<<" "<<c.size()
				<<" "<<c.capacity()
				<<" "<<c.max_size()
				<<std::endl;
	}
	auto pi= c.erase(c.begin() + 3,c.begin() + 5);
	for(int i = 0;i<10;++i){
		std::cout<<std::addressof(c[i])<<" ";
	}
	std::cout<<std::endl;
	std::cout<<std::addressof(*c.begin())
				<<" "<<std::addressof(*pi)
				<<" "<<*pi
				<<" "<<std::addressof(c[5])
				<<" "<<std::addressof(*c.end())
				<<std::endl;
#endif

}

