#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders; // for _1, _2, ...

double multiply(double first, double second)
{
    return first * second;
}

void foo(int a, int b)
{
    std::cout << "first: " << a << std::endl;
    std::cout << "second: " << b << std::endl;
}

int main()
{
    auto multi_fun = std::bind(&multiply, _1, _2);

    cout << "multiply(1.2, 4.5):  " << multiply(1.2, 4.5) << endl;
    cout << "multi_fun(1.2, 4.5): " << multi_fun(1.2, 4.5) << endl;

    auto bar = std::bind(&foo, _2, _1);

    foo(1,2);
    bar(1,2);

    return 0;
}