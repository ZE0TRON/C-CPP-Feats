#include <iostream>
using namespace std;
struct A
{
    int c;
};

class B
{
public:
    double d;
    B(double d) : d(d) {}
};

class Base
{
public:
    int c;
    virtual void display() {}
    Base()
    {
    }
    //virtual ~Base();
};

class Derived1 : public Base
{
public:
    int d;
    Derived1(int d) : d(d) {}
    ~Derived1()
    {
    }
    void display()
    {
    }
};
class Derived2 : public Base
{
public:
    float e;
    Derived2(float d) : e(d) {}
    ~Derived2()
    {
    }
    void display() {}
};

// static cast
void staticCaster(void *vPtr)
{
    B *bPtr = static_cast<B *>(vPtr);
    cout << "B is " << bPtr->d << endl;
}

// dynamic cast
// Returns null pointer if cast is not valid
void dynamicCaster(Base *vPtr)
{
    if (dynamic_cast<Derived1 *>(vPtr))
    {
        cout << "Instance of Derived 1\n";
    }
    else if (dynamic_cast<Derived2 *>(vPtr))
    {
        cout << "Instance of Derived 2\n";
    }
    else
    {
        cout << "Undefined\n";
    }
}
// regular cast

// Like static one
void regularCaster(void *vPtr)
{
    if ((Derived1 *)vPtr)
    {
        cout << "Instance of Derived 1\n";
    }
    else if ((Derived2 *)vPtr)
    {
        cout << "Instance of Derived 2\n";
    }
    else if ((float *)vPtr)
    {
        cout << "Float\n";
    }
    else
    {
        cout << "Undefined\n";
    }
}

int main()
{

    void *bPtr = new B(3.14);
    Base *d1Ptr = new Derived1(5);
    Base *d2Ptr = new Derived2(2.7);
    void *fPtr = new float;
    cout << "Static Caster\n";
    staticCaster(bPtr);
    staticCaster(d1Ptr); // Doesn't crash instead random memory access :)
    cout << "Dynamic Caster\n";
    dynamicCaster(d1Ptr);
    dynamicCaster(d2Ptr);
    cout << "Regular Caster\n";
    regularCaster(bPtr);
    regularCaster(d1Ptr);
    regularCaster(d2Ptr);
    regularCaster(bPtr);
    regularCaster(fPtr);

    return EXIT_SUCCESS;
}