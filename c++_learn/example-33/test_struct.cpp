#include <iostream>
#include <stdlib.h>


struct Node{
	float value;
	float f[512];
};



int main(){
	Node node1={1,{0}};
	Node node2=node1;
	std::cout<<(void*)node1.f <<" " <<(void*)node2.f<<std::endl;
	std::cout<<node1.value <<" " <<node2.value<<std::endl;
}
