#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
int sum(int count,...) {
    int nSum = 0;
    va_list intArgumentPointer;
    va_start(intArgumentPointer,count);
    for(int i = 0; i < count; i++){
        nSum += va_arg(intArgumentPointer,int);
    }
    va_end(intArgumentPointer);
    return nSum;
}


int main (int         argc, 
      char**      argv)
{
 system( "clear" );
 printf( "\n\n Variadic functions: \n\n" );

 printf( "\n 10 + 20 = %d ",           sum( 2, 10, 20 )  );
 printf( "\n 10 + 20 + 30 = %d ",      sum( 3, 10, 20, 30 )  );
 printf( "\n 10 + 20 + 30 + 40 = %d ", sum( 4, 10, 20, 30, 40 )  );

 printf( "\n\n" );


    return EXIT_SUCCESS;
}