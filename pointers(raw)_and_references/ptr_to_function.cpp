#include <iostream>

using namespace std;

int *foo() { return new int{2}; }
float *bar(int d = 10) { return new float{123}; }

int main()
{
    {
        int *(*bar)(void) = &foo;
        auto res = (*bar)();
        std::cout << *res << std::endl;
    }

    {
        float *(*pbar)(int) = &bar;
        std::cout << *(*pbar)(3) << std::endl;
    }

    return 0;
}