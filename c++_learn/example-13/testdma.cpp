#include <iostream>
#include <string>
#include <cstring>

struct Node{
	int arr_[10];
	std::string name;
	void operator=(const struct Node& node){
		memcpy(arr_,node.arr_,sizeof(int)*10);
		name = node.name;
	}

};

int main(){
	Node node1{{0},"node1"};

	Node node2{{0},"node2"};

	std::cout<<(void*)node1.arr_<<" "<<(void*)node2.arr_<<std::endl;

	node1.arr_[0]=1;
	std::cout<<node1.arr_[0]<<" "<<node2.arr_[0]<<std::endl;
	node2=node1;

	std::cout<<node1.arr_[0]<<" "<<node2.arr_[0]<<std::endl;
	std::cout<<(void*)node1.arr_<<" "<<(void*)node2.arr_<<std::endl;
}

