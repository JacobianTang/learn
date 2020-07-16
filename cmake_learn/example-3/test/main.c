#include<stdio.h>
#include "testFun.h"
int main(void){
	printf("hello world|\n");
	func(100);
#if 0
#ifdef NICE_DEBUG
	printf("NICE_DEBUG\n");
#endif

#if  NICE
	printf("NICE\n");
#endif
#endif
	return 0;
}
