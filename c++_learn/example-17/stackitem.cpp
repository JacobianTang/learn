#include <iostream>
#include <string>
#include <cstdlib> //for rand(),srand()
#include <cctype>
#include <ctime> //for time()

#include "stacktp.h"


const int Num  = 10 ;
using std::cin;
using std::cout;
using std::endl;


int main(){
	srand(std::time(0)); //randomize rand()
	std::cout<<"Please enter stack size: ";
	int stacksize ;
	cin>>stacksize ;

	Stack<const char*> st(stacksize);
		
	const char* in[Num]={
		"1:Hank Gilgamesh",
		"2:Kiki Ishtar",
		"3:Betty Rocker",
		"4:Ian Flagranti",
		"5:Wolfgang Kibble",
		"6:Portia Koop",
		"7:Joy Almondo",
		"8:Xaverie Paprika",
		"9:Juan Moore",
		"10:Misha Mache"
	};

	const char* out[Num];
	int processed  = 0;
	int nextin = 0;
	while(processed <Num){
		if(st.isempty()){
		   st.push(in[nextin++]);
	    }else if(st.isfull()){
		   st.pop(out[processed++]);
		}else if(std::rand()%2 && nextin <Num){
			st.push(in[nextin ++]);
		}else{
		   st.pop(out[processed++]);
		}
	}
	for(int i = 0;i<Num;i++){
		cout<<out[i]<<endl;
	}

	cout<<"Bye\n";
	return 0;
}
