#include "nsPack.h"
#include "nsPack2.h"
#include "vars.h"
#include <iostream>
extern void changeVar1(int);
extern void printVar1(void);
using namespace NS;
int main () {
    var1= 10;
    var4=3.14;
    s.c = 7;
    Vars::var1 = 5;
    Vars::var2 =2.7;
    std::cout<<s.c<<std::endl;
    std::cout<<var1<<std::endl;
    std::cout<<var4<<std::endl;
    std::cout<<Vars::var1<<std::endl;
    std::cout<<Vars::var2<<std::endl;
    changeVar1(3);
    std::cout<<"After Change : "<<Vars::var1<<std::endl;
    Vars::var1 = 23;
    printVar1();
    return EXIT_SUCCESS;
}