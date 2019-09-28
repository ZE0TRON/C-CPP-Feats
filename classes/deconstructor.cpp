#include <iostream>

// A destructor function is called automatically when the object goes out of scope:
// Destructors have same name as the class preceded by a tilde (~)
// Destructors don’t take any argument and don’t return anything

class UseMemory{
    private:
    int *_arr;
    int _size;
    public:
    UseMemory(int);
    ~UseMemory();
    void set(int,int);
    int get(int);
};

UseMemory::UseMemory(int size){
    _arr = (int *) malloc(sizeof(int) * size);
    _size = size;
    std::cout<<"Memory allocated\n";
}

UseMemory::~UseMemory(){
    delete _arr;
    std::cout<<"Memory deallocated\n";
}

void UseMemory::set(int index, int value) {
    if(index<_size-1)
        _arr[index] = value;    
}

int UseMemory::get(int index) {
    return index<_size-1 ? _arr[index] : 0;
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

UseMemory * fun4() {
    UseMemory * um;
    um = new UseMemory(110);
    um->set(1,10);
    return um;
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
    UseMemory * um = fun4();
    std::cout<<"Fun 4 object value :"<<um->get(1)<<std::endl;
    std::cout<<"Fun 5 : \n";
    fun5();
    return EXIT_SUCCESS;
}
