#ifndef STACKTP_H_
#define STACKTP_H_

template<class Type>
class Stack{
	private:
		enum {SIZE = 10};
		//Type items[MAX];///holds stack items
		int stacksize ; 
		Type* items;
		int top;///index for top stack item
	public:
		explicit Stack(int ss = SIZE);
		Stack(const Stack& st);
		~Stack(){
			delete[] items;
		};
		bool isempty(){ return top==0;};
		bool isfull(){return top==stacksize;};
		bool push(const Type& item);
		bool pop(Type& item);
		
		Stack& operator=(const Stack& st);
};



template<class Type>
Stack<Type>::Stack(int ss):stacksize(ss),top(0){
	items  = new Type[stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack & st){
	stacksize = st.stacksize;
	top = st.top;
	items  = new Type[stacksize];
	for(int i = 0;i<stacksize ;++i){
		items [i] = st.items[i];
	}
}

template<class Type>
bool Stack<Type>::push(const Type& item){
	if(top<stacksize){
	   items[top++]=item;
	   return true;
	}else{
		return false;
	}
}

template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack& st){
	if(this == &st){
		return *this;
	}
	delete[] items;
    
	stacksize = st.stacksize;
	top = st.top;
	items  = new Type[stacksize];
	for(int i = 0;i<stacksize ;++i){
		items [i] = st.items[i];
	}
	
	return *this;
}


template<class Type>
bool Stack<Type>::pop(Type& item){
	if(top >0){
		item = items[--top];
		return true;
	}else{
		return false;
	}
}

#endif