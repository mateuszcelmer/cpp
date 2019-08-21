#include <iostream>
#include <tuple>
#include <cassert>

using namespace std;

int main()
{
    int a, b;
    std::tie(a, b) = std::make_tuple(1, 2);
    std::cout << a << ", " << b << std::endl;
    return 0;
}