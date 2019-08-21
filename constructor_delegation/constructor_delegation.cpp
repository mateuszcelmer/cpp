#include <iostream>

using namespace std;

class A
{
    int x, y, z;

public:
    A() : x{0}, y{0}, z{0} {}
    A(int z) : A()
    {
        this->z = z;
    }
    friend ostream &operator<<(ostream &out, A &a);
};

ostream &operator<<(ostream &out, A &a)
{
    out << a.x << ", " << a.y << ", " << a.z;
    return out;
}

int main()
{
    A a(30);
    cout << a;
    return 0;
}