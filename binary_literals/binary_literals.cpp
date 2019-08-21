#include <iostream>

using namespace std;

int main()
{
    int a = 0b1111;
    std::cout << a << std::endl;

    int b = 0b1111'1111;
    std::cout << b << std::endl;

    int c = 1'000'000'000;
    std::cout << c << std::endl;

    return 0;
}