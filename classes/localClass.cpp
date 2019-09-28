#include <iostream>

class Test {
    public:
    void print() {
        std::cout << "This is global class \n";
    }
};


void fun(){
    class Test {
        public:
        void print(){
            std::cout << "This is local class \n";
        }
    };
    Test test;
    test.print();
}

int main () {

    // Code 
    Test test;
    test.print();
    fun();
    return EXIT_SUCCESS;
}