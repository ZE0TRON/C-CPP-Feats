#include <iostream>

using namespace std;

class base {
    public:
    virtual void vPrint() {
        cout<<"Base class vPrint"<<endl;
    }
    void print(){
        cout<<"Base class vPrint"<<endl;
    }
};

class derived:public base {
    public:
    void vPrint(){
        cout<<"Derived class vPrint"<<endl;
    }
    void print() {
        cout<<"Derived class vPrint"<<endl;
    }
};



int main () {
    base * bPtr;
    derived d;
    bPtr = &d;
    bPtr->print();
    bPtr->vPrint(); 
    // Code 

    return EXIT_SUCCESS;
}