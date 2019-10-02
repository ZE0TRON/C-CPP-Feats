// Reference : https://www.learncpp.com/cpp-tutorial/15-4-stdmove/
// In C++11, std::move is a standard library function that serves a single purpose
// -- to convert its argument into an r-value. We can pass an l-value to std::move,
// and it will return an r-value reference. std::move is defined in the utility header.

#include <iostream>
#include <string>
#include <utility>
#include <vector>


template <class T>
void copySwap(T &a, T &b)
{
    T tmp(a); // invokes copy constructor
    a = b;    // invokes copy assignment
    b = tmp;  // invokes copy assignment
}
template <class T>
void moveSwap(T &a, T &b)
{
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

template <class T>
void copy_push_back(const std::vector<T> &v, const T &elem)
{
    v.push_back(elem);
}

template<class T>
void move_push_back(const std::vector<T>& v,T& elem) // Cant be const elem because std move clears the elem after move
{
    v.push_back(std::move(elem));
}


int main()
{
    std::string x("abc");
    std::string y("de");

    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';

    copySwap(x, y);
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    moveSwap(x, y);
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    std::vector<std::string> v1,v2;
    copy_push_back(v1,x);
    move_push_back(v2,y);
    return 0;
}