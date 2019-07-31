#include <iostream>
#include <variant>
#include <string>

using namespace std;

int main()
{
    std::variant<int, double, std::string> v{12};
    auto a1 = std::get<int>(v);
    auto a2 = std::get<0>(v);

    v = 12.1;
    auto a3 = std::get<double>(v);
    auto a4 = std::get<1>(v);

    v = "abc";
    auto a5 = std::get<std::string>(v);
    auto a6 = std::get<2>(v);

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << a4 << std::endl;
    std::cout << a5 << std::endl;
    std::cout << a6 << std::endl;

    return 0;
}