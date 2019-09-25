#include "vars.h"
#include <iostream>
void changeVar1(int val) {
    Vars::var1 = val;
}

void printVar1(){
    std::cout<<"Var1 : "<<Vars::var1<<std::endl;
}