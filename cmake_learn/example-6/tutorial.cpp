#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc,char* argv[]){
	double inputValue=atof(argv[1]);
#ifdef USE_MYMATH
	double outputValue=mysqrt(inputValue);
#else

	double outputValue=sqrt(inputValue);
#endif
	fprintf(stdout,"the square root of %g is %g\n",inputValue,outputValue);
	return 0;
}
