#include <future>
#include <vector>
#include <iostream>
#include <thread>
typedef unsigned long long ull;



int main() {
    auto f1 = [](std::vector<int> &v,unsigned int left, unsigned int right) {
        ull acm = 0;
        for( unsigned int i= left;i<right;i++){
            acm+=v[i];
        }
        return acm;
    };
    std::vector<int> v = {1,2,3,4,5};
    auto t1 = std::async(f1,std::ref(v),0,v.size()/2);
    auto t2 = std::async(f1,std::ref(v),v.size()/2,v.size());

    unsigned long long acm1 = t1.get();
    unsigned long long acm2 = t2.get();

        std::cout << "acm1: " << acm1 << std::endl;
        std::cout << "acm2: " << acm2 << std::endl;
        std::cout << "acm1 + acm2: " << acm1 + acm2 << std::endl;
};
