#include <iostream>

using namespace std;

class A
{
    int x;

public:
    friend std::ostream &operator<<(std::ostream &out, const A &obj)
    {
        out << "Test : " << obj.x << std::endl;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, A &obj)
    {
        in >> obj.x;
        return in;
    }
    A operator()(int x, int y, int z)
    {
        A obj;
        obj.x = x;
        return obj;
    }
};

int main()
{
    A a;
    cin >> a;
    cout << a;
    a = a(555, 0, 0);
    cout << a;

    return 0;
}