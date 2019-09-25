#include <iostream> 
using namespace std; 
  
// Variable created inside namespace 
namespace first 
{ 
    int val = 500; 
}
// Like adding additional variables to same namespace
namespace first {
    int c = 130;
    int d = 120;
}
// Global variable 
int val = 100; 
  
int main() 
{ 
    // Local variable 
    int val = 200; 
  
    // These variables can be accessed from 
    // outside the namespace using the scope 
    // operator :: 
    cout << first::val << '\n';  
    cout << first::c << '\n';
    cout << first::d << '\n';    
    return 0; 
} 