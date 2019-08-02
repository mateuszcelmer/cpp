#include <iostream>

using namespace std;

class A
{
    int x;

public:
    A(int x) : x(x){};
    A(const A &) = delete;
    A &operator=(const A &) = delete;
};

int main()
{

    A x{123};
    A y = x; // error -- call to deleted copy constructor
    y = x;   // error -- operator= deleted
    return 0;
}