// Reference : https://www.learncpp.com/cpp-tutorial/15-2-rvalue-references/
#include <iostream>

void fun(const int &lRef) //l-value arguments will select this function
{
    std::cout << "l-value reference to const\n";
}

void fun(int &&rRef) // r-value arguments will select this function
{
    std::cout << "r-value reference\n";
}

int main()
{
    int x = 5;
    fun(x); // L value
    fun(5); // R value
    int &&ref = 5;
    fun(ref); // Even if its a reference to R value ref it self is a lvalue
    return EXIT_SUCCESS;
}