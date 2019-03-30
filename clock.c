#include "stdio.h"  
#include "stdlib.h"  
#include "time.h"
  
int main( void )  
{  
   long    i = 100000;  
   clock_t start, finish;  
   double  duration;  
   /* 测量一个事件持续的时间*/  
   printf( "Time to do %ld empty loops is ", i );  
   start = clock();  
   char buffer [50];
   int num = 1234;
   while( i-- )
   {
       //sprintf(buffer, "%d", num);
       itoa(num, buffer, 10);
   }
   finish = clock();  
   duration = (double)(finish - start) / CLOCKS_PER_SEC;  
   printf( "%f seconds\n", duration );  
}  
