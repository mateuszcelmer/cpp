#include <iostream>
#include <functional>

using namespace std;

template <typename Callable>
class Proxy
{
    Callable c;

public:
    Proxy(Callable c) : c(c) {}

    template <typename... Args>
    decltype(auto) operator()(Args &&... args)
    {
        return std::invoke(c, std::forward<Args>(args)...);
    }
};

auto add = [](auto x, auto y) { return x + y; };

int main()
{
    Proxy<decltype(add)> proxy(add);
    auto res = proxy(2, 3);
    std::cout << res << std::endl;
    return 0;
}