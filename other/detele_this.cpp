#include <iostream>

using namespace std;

class A
{
public:
    void foo() { delete this; }
    ~A() { std::cout << "Destruktor" << std::endl; }
};

int main()
{
    A *a = new A();
    a->foo();

    return 0;
}