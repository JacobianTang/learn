#include <stdio.h>
#include "testFun1.h"

void func1(int data){
	printf("data is %d\n",data);


#ifdef NICE_DEBUG
	printf("NICE_DEBUG\n");
#endif

#if  NICE
	printf("NICE\n");
#endif

}


void testJump(){
	int data=0;
	func1(data);
}
	
