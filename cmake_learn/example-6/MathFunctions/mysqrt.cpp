#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <time.h>
#include "MathFunctions.h"
//this function copy from InvSqrt
double mysqrt(double number)  
{  
     float new_guess;
     float last_guess;
     
     if (number < 0) {
         printf("Cannot compute the square root of a negative number!\n");
         return -1;
     }
#ifdef NICE_DEBUG
	printf("NICE_DEBUG\n");
#endif

     new_guess = 1;
     do {
         last_guess = new_guess;
         new_guess = (last_guess + number / last_guess) / 2;
         printf("%.15e\n", new_guess);
     } while (new_guess != last_guess);
     
     return new_guess;
}  
