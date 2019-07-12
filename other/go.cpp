#include <iostream>

using namespace std;

class A
{
public:
    int x = 1;
    A(){};
    ~A() { std::cout << "Destruktor" << x << std::endl; }
};

int main()
{
    A a;
    std::cout << "asd" << std::endl;
    auto &&c = std::move(a);
    auto &d = a;
    d.x = 5;
    c.x = 3;
    auto e = std::move(a);
    e.x = 10;
    std::cout << "qwe" << std::endl;

    std::cout << c.x << std::endl;
    return 0;
}