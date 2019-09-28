#include <iostream>

// A destructor function is called automatically when the object goes out of scope:
// Destructors have same name as the class preceded by a tilde (~)
// Destructors don’t take any argument and don’t return anything

class UseMemory{
    private:
    int *_arr;
    public:
    UseMemory(int);
    ~UseMemory();
};

UseMemory::UseMemory(int size){
    _arr = (int *) malloc(sizeof(int) * size);
    std::cout<<"Memory allocated\n";
}
UseMemory::~UseMemory(){
    delete _arr;
    std::cout<<"Memory deallocated\n";
}

void fun(){
    UseMemory um(5);
}

void fun2(){
    UseMemory um(10);
    // This line causes segmentation error
    //delete &um;
}

void fun3(){
    UseMemory * um;
}

void fun4() {
    UseMemory * um;
    um = new UseMemory(110);
}

void fun5(){
    UseMemory * um;
    um = new UseMemory(100);
    delete um;
}

int main () {

    std::cout<<"Fun 1 : \n";
    fun();
    std::cout<<"Fun 2 : \n";
    fun2();
    std::cout<<"Fun 3 : \n";
    fun3();
    std::cout<<"Fun 4 : \n";
    fun4();
    std::cout<<"Fun 5 : \n";
    fun5();
    return EXIT_SUCCESS;
}
