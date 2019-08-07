#include <iostream>

using namespace std;

class X
{
public:
    X() { std::cout << "X Constructor" << std::endl; }
};

class A
{
    X x;

public:
    A() { std::cout << "A Constructor" << std::endl; }
};

class B : A
{
    X y;

public:
    B() { std::cout << "B Constructor" << std::endl; }
};

int main()
{
    B b;
    return 0;
}