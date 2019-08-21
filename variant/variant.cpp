#include <iostream>
#include <variant>
#include <string>

using namespace std;

int main()
{
    std::variant<int, double, std::string> v{12};
    auto a1 = std::get<int>(v);
    auto a2 = std::get<0>(v);
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;

    v = 12.1;
    auto a3 = std::get<double>(v);
    auto a4 = std::get<1>(v);
    std::cout << a3 << std::endl;
    std::cout << a4 << std::endl;

    v = "abc";
    auto a5 = std::get<std::string>(v);
    auto a6 = std::get<2>(v);
    std::cout << a5 << std::endl;
    std::cout << a6 << std::endl;

    try
    {
        std::variant<int, double, std::string> asd{10};
        auto ww = std::get<2>(asd);
        std::cout << ww << std::endl;
    }
    catch (std::bad_variant_access e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}