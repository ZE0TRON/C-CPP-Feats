#include <iostream> 
using namespace std; 
  
// unnamed namespace declaration
// Specific to this file
// If extern rel -> rel is ambigious
// If declare rel in another NS and using namespace NS -> rel is ambigious
// Replacement of static variables 
namespace 
{ 
   int rel = 300;  
} 
  
int main() 
{ 
   cout << rel << "\n"; // prints 300 
   return 0; 
} 