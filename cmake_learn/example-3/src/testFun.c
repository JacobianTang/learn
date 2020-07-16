#include <stdio.h>
#include "testFun.h"

void func(int data){
	printf("data is %d\n",data);

#ifdef NICE_DEBUG
	printf("NICE_DEBUG\n");
#endif

#if  NICE
	printf("NICE\n");
#endif

}
	
