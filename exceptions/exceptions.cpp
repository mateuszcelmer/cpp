#include <iostream>

using namespace std;

class A
{
public:
    int foo()
    {
        throw 32;
        return 10;
    }
    ~A()
    {
        std::cout << "destruktor" << std::endl;
    }
};

int main()
{
    A a;
    try
    {
        std::cout << a.foo() << std::endl;
    }
    catch (int &e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}