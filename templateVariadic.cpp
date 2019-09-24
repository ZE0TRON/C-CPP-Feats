#include <iostream>
using namespace std;

void print() {
    cout<< "I am empty function for recursive base case"<<endl;
}

template <typename T, typename... Types>
void print(T var1, Types... var2){
    cout << var1 << endl ; 
  
    print(var2...) ; 
}

int main(){
    print(1,2,3.14,"Anything","Can be passed","LOL");
    return EXIT_SUCCESS;
}