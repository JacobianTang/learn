#include <iostream>
#include <cstdlib>
#include <memory>
using namespace std;

class  Queue{
	public:
		class Node;
		enum {Q_SIZE = 10};
	private:
		Node* front;
		Node* rear;
		int items;
		const int qsize;
		const static int  NUM = 10;
		double len_ = 0;
		static int count;
		const string name="queue";
};

int Queue::count = 0;

class Queue::Node{
	public:
		int item;
		Node* next;
		const int& get_item(){
			return item;
		}
		void print(const string& str);
};

void Queue::Node::print(const string& str){
		cout<<"Queue::Node:print: "<<str<<endl;

}

int main(){
	Queue::Node node;
	cout<<node.get_item()<<endl;
	node.print("hello world");

}





