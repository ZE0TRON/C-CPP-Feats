#include <iostream>

class Test {
    public:
    void print() {
        std::cout << "This is global class \n";
    }
    void method();
};
void Test::method() {
    std::cout<< "Global outside decleration \n";
}

void fun(){
    class Test {
        public:
        void print(){
            std::cout << "This is local class \n";
        }
        // No static data allowed here but can contain static functions
        // Member methods of local class can only access static and enum variables of the enclosing function. 
        // Non-static variables of the enclosing function are not accessible inside local classes.
        // Local classes can access global types, variables and functions. Also, local classes can access other local classes of same function..
        void method();
    };
    // This gives an error
    // void Test::method(){
    //     std::cout<<"Local in function decleration";
    // }
    
    
    Test test;
    test.print();
    // This gives an error since local class overrides the  global one and method is not defined
    // test.method();
}

void fun2(){
    // Also an example of local struct
    struct S {
        int data;
        void func(){
        std::cout<<"This is local struct func \n";
        }
    };
    S s;
    s.data =5;
    s.func();
}


int main () {

    // Code 
    Test test;
    test.print();
    fun();
    fun2();
    return EXIT_SUCCESS;
}