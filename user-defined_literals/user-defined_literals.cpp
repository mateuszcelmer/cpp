#include <iostream>

using namespace std;

int operator"" _int(const char *str, std::size_t)
{
    return std::stoi(str);
}

int main()
{
    auto a = "123"_int;
    int b = "321"_int;
    std::cout << "987"_int << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a + b << std::endl;
    return 0;
}