// Reference : https://www.learncpp.com/cpp-tutorial/15-3-move-constructors-and-move-assignment/
/*
When are the move constructor and move assignment called?
The move constructor and move assignment are called when those functions have been defined,
and the argument for construction or assignment is an r-value. Most typically,
this r-value will be a literal or temporary value.
In most cases, a move constructor and move assignment operator will not be provided by default,
unless the class does not have any defined copy constructors, copy assignment,
move assignment, or destructors. However, the default move constructor and move assignment do
the same thing as the default copy constructor and copy assignment (make copies, not do moves).
Rule: If you want a move constructor and move assignment that do moves, you’ll need to write them yourself.

If we construct an object or do an assignment where the argument is an l-value, the only thing
we can reasonably do is copy the l-value. We can’t assume it’s safe to alter the l-value, because it
may be used again later in the program. If we have an expression “a = b”, we wouldn’t reasonably
expect b to be changed in any way.

However, if we construct an object or do an assignment where the argument is an r-value, then we know that
r-value is just a temporary object of some kind. Instead of copying it (which can be expensive), we can simply
transfer its resources (which is cheap) to the object we’re constructing or assigning. This is safe to do because
the temporary will be destroyed at the end of the expression anyway, so we know it will never be used again!
*/

#include <iostream>

template <class T>
class Auto_ptr4
{
    T *m_ptr;

public:
    Auto_ptr4(T *ptr = nullptr) : m_ptr(ptr) {}
    ~Auto_ptr4()
    {
        delete m_ptr;
    }
    // Copy constructor
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr4(const Auto_ptr4 &a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
    // Move constructor
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr4(Auto_ptr4 &&a) : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
    }

    // Copy assignment
    // Do deep copy of a.m_ptr to m_ptr
    Auto_ptr4 &operator=(const Auto_ptr4 &a)
    {
        // Self-assignment detection
        if (&a == this)
            return *this;

        // Release any resource we're holding
        delete m_ptr;

        // Copy the resource
        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    //Move assignment
    // Transfer owenership of a.m_ptr to m_ptr
    Auto_ptr4 &operator=(Auto_ptr4 &&a)
    {
        if (&a == this)
            return *this;
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
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

Auto_ptr4<Resource> generateResource()
{
    Auto_ptr4<Resource> res(new Resource);
    return res; // this return value will invoke the copy constructor;
}

int main()
{
    Auto_ptr4<Resource> mainres;
    mainres = generateResource(); // This assignment will invoke the copy assignment
    return EXIT_SUCCESS;
}