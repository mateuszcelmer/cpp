#include <iostream>

using namespace std;

class A
{
public:
    int i = 10;
    int &get() noexcept { return i; }
    A() { std::cout << "Constructor " << this << std::endl; }
    A(A &&a)
    {
        std::cout << "Copy Constructor&& " << this << std::endl;
        i = a.i;
    }
    ~A() { std::cout << "Destructor " << this << std::endl; }
};

int main()
{
    A a;
    std::cout << "a.i " << a.i << std::endl;

    a.i = 999;
    auto b = std::move(a);
    std::cout << "a.i " << a.i << std::endl;
    std::cout << "b.i " << b.i << std::endl;

    a.get() = 5;
    std::cout << "a.i " << a.i << std::endl;

    int &y = a.get();
    y = 8;
    int &z = b.get();
    z = 11;
    std::cout << "a.i " << a.i << std::endl;
    std::cout << "b.i " << b.i << std::endl;

    return 0;
}