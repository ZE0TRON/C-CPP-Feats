#include <iostream>
using namespace std;

namespace ns1{
    namespace ns2{
        namespace ns3{
            int val =27;
        }
    }
}

namespace alias = ns1::ns2::ns3;

int main () {

    // Code 
    cout<<alias::val<<endl;
    return EXIT_SUCCESS;
}