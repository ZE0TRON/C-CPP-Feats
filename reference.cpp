#include <iostream>
#include <vector>
using namespace std;

struct S{
    string a;
    int b;
    void change(int c){
        b =c;
    }
};
// Instead of copying the struct to a new one
// The reference is passed
// Const used to ensure that it can't change any values of S
void printS(const S& s){
    cout<<"String : "<<s.a<<endl;
    cout<<"Int : "<<s.b<<endl;
    //s.b = 5;
    // Causes compile error since s is const 
    // s.change(10);
    // Also causes compile error since it changes the s
}

template<typename T>
void printVector(const vector<T>& v ) {
    for(T x: v) {
        cout<<x<<", ";
    }
}


template <typename T>
void forEach(vector<T>& v){

    for (T x :v) {
        x+=5;
    }
    cout<<"\nAfter forEach without ref"<<endl;
    printVector(v);

    for(T& x : v){
        x+=5;
    }
    cout<<"\nAfter forEach with ref"<<endl;
    printVector(v);
}



void swap(int& x, int& y) {
    int temp = x;
    x =y;
    y=temp;
}


int main () {

    int x;
    int& ref_int = x;

    ref_int = 20; // Now x is 20;
    cout<<"X is "<<x<<endl;
    x = 30; // Now ref_int is 30;
    cout<<"Ref_int is "<<ref_int<<endl;
    // delete &x;
    // The ref_int refs to nothing causes error;
    // cout<<"X is deleted ?"<<ref_int<<endl;
    int c =10,d=15;
    cout<<"Before swap "<<c<<","<<d<<endl;
    swap(c,d);
    cout<<"After swap "<<c<<","<<d<<endl;
    S s = {"a",1};
    printS(s);
    vector<double> v = {1,1.0,3.15};
    cout<<"Before forEach"<<endl;
    printVector(v);
    forEach(v);
    cout<<"\nAfter forEach func"<<endl;
    printVector(v);
    return EXIT_SUCCESS;
}