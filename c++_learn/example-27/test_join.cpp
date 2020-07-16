#include <iostream>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <cmath>
#include <string>
#include <cstring>
#include "test_head.h"
typedef struct ResStruct{
	float res;
	char str[100];
	ResStruct(float res_,std::string str_){
		res=res_;
		memcpy(str,str_.c_str(),str_.size());
	}
}ResStruct;


void* mysqrt(void* t){
	float input_ = *(float*)t;
	float res = std::sqrt(input_);
	printf("the result is %f\n",res);
	ResStruct* res_rtn=new ResStruct(res,"good boy");
	std::cout<<(void*)res_rtn<<std::endl;
	return (void*)(res_rtn);
}

int  main(){
	pthread_t test_tid;
	float t = 3;
	pthread_create(&test_tid,NULL,mysqrt,&t);
    ResStruct*  rtn;		
	pthread_join(test_tid,(void**)&rtn);
	std::cout<<rtn->str <<" " <<rtn->res<<std::endl;
	std::cout<<(void*)rtn<<std::endl;
	delete rtn;
}




