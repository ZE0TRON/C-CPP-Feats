// constexpr function for product of two numbers. 
// By specifying constexpr, we suggest compiler to  
// to evaluate value at compiler time 
#include <iostream>
#include <ctime>
using namespace std; 
  
constexpr long int fib(int n) 
{ 
    return (n <= 1)? n : fib(n-1) + fib(n-2); 
} 

long int nat_fib(int n) {
    return (n <= 1)? n : fib(n-1) + fib(n-2); 
} 
  
int main () 
{ 
    // value of res is computed at compile time.
    clock_t start = clock();  
    const long int res = nat_fib(30);
    clock_t end = clock();
    cout<< "Natural fib time : "<<end-start<<"Result : "<< res<<endl; 
     start = clock();  
   const long int res2 = fib(30);
     end = clock();
    cout<< "Const fib time : "<<end-start<<"Result : "<< res2<<endl; 
    return 0; 
} 