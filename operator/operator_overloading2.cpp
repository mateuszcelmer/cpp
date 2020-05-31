#include <iostream>

class A
{
public:
    int x;
};

std::ostream& operator<<(std::ostream &out, const A& a)
{
    out << "T = " << a.x;
    return out;
}

int main()
{
    A a;
    a.x = 321;
    std::cout << a;

    return 0;
}