#include <algorithm>
#include <cmath>
#include <iostream>
void mySort(float *x, unsigned n)
{
    std::sort(x, x + n,
              [](float a, float b) {
                  return sin(a) < sin(b);
              });
    for (int i = 0; i < n; i++)
    {
        std::cout << *x << ",";
        x++;
    }
    std::cout << "\n";
}

int main()
{
    float f_arr[] = {3.14, 5, 0, 0.3};
    float f_parr[] = {1, 0.5, .07};
    mySort(f_arr, 4);
    mySort(f_parr, 3);
}