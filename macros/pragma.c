#include<stdio.h>  
    
void func1();  
void func2();  
    
void __attribute__((constructor)) func1();  // alternative not in gcc=>  #pragma startup func1
void __attribute__((destructor)) func2();  // alternative not in gcc => #pragma exit func2 
// Disables the use of scanf in the project
// #pragma GCC poision scanf;

// #pragma warn +xxx (To show the warning)
// #pragma warn -xxx (To hide the warning)
// #pragma warn .xxx (To toggle between hide and show)
// #pragma warn -rvl /* return value */ 
// #pragma warn -par /* parameter never used */ 
// #pragma warn -rch /*unreachable code */ 

void func1()  
{  
    printf("Inside func1()\n");  
}  
    
void func2()  
{  
    printf("Inside func2()\n");     
}  
    
int main()  
{  
    printf("Inside main()\n");  
        
    return 0;  
}  