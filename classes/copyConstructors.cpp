// Reference : https://www.learncpp.com/cpp-tutorial/15-3-move-constructors-and-move-assignment/
#include <iostream>
/*
Copy constructors are used to initialize a class by making a copy of an object of the same class.
Copy assignment is used to copy one class to another existing class.
By default, C++ will provide a copy constructor and copy assignment operator if one is not explicitly provided.
These compiler-provided functions do shallow copies,
which may cause problems for classes that allocate dynamic memory.
So classes that deal with dynamic memory should override these functions to do deep copies.
*/

template <class T>
class Auto_ptr3
{
    T *m_ptr;

public:
    Auto_ptr3(T *ptr = nullptr) : m_ptr(ptr) {}
    ~Auto_ptr3()
    {
        delete m_ptr;
    }

    //Copy Constructor
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr3(const Auto_ptr3 &a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    // Copy assignment
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr3 &operator=(const Auto_ptr3 &a)
    {
        if (&a == this)
        {
            return *this;
        }

        // Release any resource we're holding
        delete m_ptr;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }
    T &operator*() const { return *m_ptr; }
    T *operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed \n"; }
};

Auto_ptr3<Resource> generateResource()
{
    Auto_ptr3<Resource> res(new Resource);
    std::cout << "Before generateResource return\n";
    return res; // this return value will invoke the copy constructor;
}

int main()
{
    Auto_ptr3<Resource> mainres;
    mainres = generateResource(); // This assignment will invoke the copy assignment
    return EXIT_SUCCESS;
}
/*
1) Inside generateResource(), local variable res is created and initialized with a dynamically allocated Resource, 
which causes the first “Resource acquired”.
2) Res is returned back to main() by value. We return by value here because res is a local variable --
it can’t be returned by address or reference because res will be destroyed when generateResource() ends. 
So res is copy constructed into a temporary object. Since our copy constructor does a deep copy,
a new Resource is allocated here, which causes the second “Resource acquired”.
3) Res goes out of scope, destroying the originally created Resource, which causes the first “Resource destroyed”.
4) The temporary object is assigned to mainres by copy assignment. Since our copy assignment also does a deep copy, 
a new Resource is allocated, causing yet another “Resource acquired”.
5) The assignment expression ends, and the temporary object goes out of expression scope and is destroyed, 
causing a “Resource destroyed”.
6) At the end of main(), mainres goes out of scope, and our final “Resource destroyed” is displayed.
*/