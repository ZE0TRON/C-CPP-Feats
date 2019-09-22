// Compile this file with -D COMPILE 
// -D FUNC=func1 -U DONT_COMPILE 
// flags

#include <stdio.h>
#include <string.h>
#if #system (gnu)
#warning May not work properly on gnu based.
#endif

#ifdef __mach__
#error Cant work with that.
#endif

#define LINUX 1

#ifdef LINUX
#warning Not consistent in linux.
#endif


#ifndef COMPILE
#error Cant compile
#endif

#ifdef DONT_COMPILE
#error Cant compile
#endif
// #ifdef unix
// #error Cant work on unix
// #endif
typedef void (*FUNC_P)(void);

void func1(){
    printf("LOLLLL\n");
}
int main(){
    printf("%s\n",__DATE__);
    FUNC_P func_p = &FUNC;
    (*func_p)();
    return 0;
}