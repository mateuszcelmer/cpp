#include <iostream>
#include <any>

using namespace std;

class A
{
public:
    friend ostream &operator<<(ostream &out, A &obj)
    {
        out << "Object A";
        return out;
    }
};

int main()
{
    std::any x{5};
    x.has_value();         // == true
    std::any_cast<int>(x); // == 5
    std::any_cast<int &>(x) = 10;
    std::any_cast<int>(x); // == 10

    x = 3.14;
    auto res = std::any_cast<double>(x);
    std::cout << res << std::endl;

    x = A();
    auto res2 = std::any_cast<A>(x);
    std::cout << res2 << std::endl;

    return 0;
}