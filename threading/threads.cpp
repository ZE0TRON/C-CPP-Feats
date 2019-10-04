#include <iostream>
#include <vector>
#include <thread>

class multFunctor
{
private:
    long long int _res;

public:
    void operator()(const std::vector<int> &v, unsigned int begin, unsigned int end)
    {
        _res = 1;
        for (unsigned int i = begin; i < end; i++)
        {
            _res *= v[i];
        }
    }

    long long int getRes()
    {
        return _res;
    }
};

void mult_func(const std::vector<int> &v, long long int &res, unsigned int begin, unsigned int end)
{
    for (unsigned int i = begin; i < end; i++)
    {
        res *= v[i];
    }
}

int main()
{
    // Using Function Pointers

    long long int res1 = 1;
    long long int res2 = 1;
    //static const int v_arr[] = {1, 3, 4, 5, 6};
    //std::vector<int> v(v_arr, sizeof(v_arr) / sizeof(v_arr[0]));
    // C++11 and above can use this easily
    std::vector<int> v = {1, 3, 4, 5, 6};
    // Creating threads
    // Used std::ref because otherwise everything would be pass by value
    std::thread t1(mult_func, std::ref(v), std::ref(res1), 0, v.size() / 2);
    std::thread t2(mult_func, std::ref(v), std::ref(res2), v.size() / 2, v.size());

    // Block the program until the threads end
    t1.join();
    t2.join();
    std::cout << "Res1: " << res1 << std::endl;
    std::cout << "Res2: " << res2 << std::endl;
    std::cout << "Res1 * Res2: " << res1 * res2 << std::endl;

    // Using functors

    // Creating functor instances
    // In that way we can hold the result of the thread inside the instance
    multFunctor multiplier1 = multFunctor();
    multFunctor multiplier2 = multFunctor();

    std::thread t3(std::ref(multiplier1), std::ref(v), 0, v.size() / 2);
    std::thread t4(std::ref(multiplier2), std::ref(v), v.size() / 2, v.size());

    // Wait for threads to end
    t3.join();
    t4.join();

    std::cout << "Res1: " << multiplier1.getRes() << std::endl;
    std::cout << "Res2: " << multiplier2.getRes() << std::endl;
    std::cout << "Res1 * Res2: " << multiplier1.getRes() * multiplier2.getRes() << std::endl;

    // Using Lambda Functions

    long long int res3 = 1;
    long long int res4 = 1;
    std::thread t5([&res3, &v] {
        for (unsigned int i = 0; i < v.size() / 2; ++i)
        {
            res3 *= v[i];
        }
    });
    std::thread t6([&res4, &v] {
        for (unsigned int i = v.size() / 2; i < v.size(); ++i)
        {
            res4 *= v[i];
        }
    });
    t5.join();
    t6.join();
    std::cout << "Res1: " << res3 << std::endl;
    std::cout << "Res2: " << res4 << std::endl;
    std::cout << "Res1 * Res2: " << res3 * res4 << std::endl;
}