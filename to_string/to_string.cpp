#include <iostream>

using namespace std;

int main()
{
    auto a = std::to_string(1.23);
    std::cout << a << std::endl;

    auto b = std::to_string(123);
    std::cout << b << std::endl;

    return 0;
}