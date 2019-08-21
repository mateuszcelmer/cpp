#include <iostream>

using namespace std;

template <typename... Args>
auto sum(Args... args)
{
    return (... + args);
}

int main()
{
    auto res = sum(1.0, 2.0f, 3);
    std::cout << res << std::endl;
    return 0;
}