#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders; // for _1, _2, ...

double multiply(double first, double second)
{
    return first * second;
}

int main()
{
    auto multi_fun = std::bind(&multiply, _1, _2);

    cout << "multiply(1.2, 4.5):  " << multiply(1.2, 4.5) << endl;
    cout << "multi_fun(1.2, 4.5): " << multi_fun(1.2, 4.5) << endl;

    return 0;
}