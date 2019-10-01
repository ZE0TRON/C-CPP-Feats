//Example from : https://www.geeksforgeeks.org/g-fact-93/

#include <iostream>
using namespace std;
class Complex
{
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // A method to compare two Complex numbers
    bool operator==(Complex rhs)
    {
        return (real == rhs.real && imag == rhs.imag) ? true : false;
    }
};

class Complex2
{

private:
    double real;
    double imag;

public:
    // Default constructor
    explicit Complex2(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // A method to compare two Complex numbers
    bool operator==(Complex2 rhs)
    {
        return (real == rhs.real && imag == rhs.imag) ? true : false;
    }
};

int main()
{
    // a Complex object
    Complex com1(3.0, 0.0);
    // C++ implicitly calls the constructor for Complex on 3.0 like Complex(3.0,0) and this evaluates to same
    if (com1 == 3.0)
        cout << "Same";
    else
        cout << "Not Same";
    Complex2 com2(3.0, 0.0);
    // This generates a compiler error since explicit keywords tells that you can only call the constructor of this class
    // explicitly
    // if (com2 == 3.0)
    //     cout << "Same";
    // else
    //     cout << "Not Same";
    if (com2 == (Complex2)3.0) // We can still typecast it explicitly
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}