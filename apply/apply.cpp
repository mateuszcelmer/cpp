#include <iostream>
#include <functional>

using namespace std;

int main()
{

    auto add = [](int x, int y) {
        return x + y;
    };

    auto res = std::apply(add, std::tuple(1, 2));

    std::cout << res << std::endl;

    return 0;
}