#include <iostream> 
using namespace std; 
// Nested namespace 
int val= 10;
namespace out 
{ 
  int val = 5;  
  namespace in 
  {   // Looking for val starts from the inner that's why val2 get the value 5
      int val2 = val;     
  } 
} 
  
int main() 
{ 
  cout << out::in::val2<<endl;   // prints 5 
  return 0; 
} 