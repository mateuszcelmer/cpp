#include <iostream>

using namespace std;

template <typename T>
auto &f(T &t)
{
    return t;
}

int main()
{
    auto g = [](auto &x) -> auto & { return f(x); };

    int y = 123;
    int &z = g(y);

    z = 321;

    std::cout << y << " : " << z << std::endl;

    return 0;
}