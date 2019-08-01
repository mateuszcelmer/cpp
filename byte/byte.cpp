#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    std::byte a{0};
    std::byte b{0xFF};
    std::byte d{0b0000'0111};
    int i = std::to_integer<int>(b);
    std::byte c = a & b;
    int j = std::to_integer<int>(c);
    int k = std::to_integer<int>(d);

    std::cout << i << ", "
              << j << ", "
              << k << ", " << std::endl;
    return 0;
}