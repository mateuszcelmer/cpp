#include <iostream>
#include <optional>

using namespace std;

std::optional<std::string> create(bool b)
{
    if (b)
    {
        return "Godzilla";
    }
    else
    {
        return {};
    }
}

int main()
{
    auto a = create(false).value_or("empty");
    auto b = create(true).value();

    std::cout << a << std::endl
              << b << std::endl;

    if (auto str = create(true))
    {
        std::cout << "cond 1" << std::endl;
    }

    if (auto str = create(false))
    {
        std::cout << "cond s" << std::endl;
    }
    return 0;
}