#include <iostream>
using namespace std;

namespace ns {
    class Example {
        public:
        void print() {
            cout<<"ns:Example:print()\n";
        }
        static void sPrint() {
            cout<<"ns:Example:sPrint()\n";
        }
    };
    class C;

    int Return0(){
        return 0;
    }

    template <typename T>
    void printElem(T elem);

}

class ns::C {
    public:
        void print() {
            cout<<"ns:C:print()\n";
        }
};

template <typename T>
void ns::printElem(T elem) {
    cout<<elem<<endl;
}

int main() {
    ns::Example example;
    example.print();
    ns::Example::sPrint();
    ns::C *c = new ns::C();
    c->print();
    ns::Return0();
    ns::printElem<double>(3.14);
    return EXIT_SUCCESS;
}