#include <iostream>

using namespace std;

int main()
{
    auto x = 1;
    auto f = [&r = x, x = x * 10] {++r;
    return r+x; };

    std::cout << "x = " << x << std::endl;

    auto k = f();

    std::cout << k << std::endl;
    std::cout << "x = " << x << std::endl;

    return 0;
}