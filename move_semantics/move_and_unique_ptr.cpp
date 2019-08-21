#include <iostream>
#include <memory>
using namespace std;

class A
{

public:
    int i = 5;
    A() { std::cout << "Ctor " << i << std::endl; }
    ~A() { std::cout << "Dtor " << i << std::endl; }
};

int main()
{
    auto upa = make_unique<A>();
    auto upb(std::move(upa));
    upb->i = 10;
    std::cout << upb->i << std::endl;
    return 0;
}

// Ctor 5
// 10
// Dtor 10