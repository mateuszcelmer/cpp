#include <iostream>
#include <functional>

using namespace std;

int main()
{

    auto add = [](int x, int y, int z) {
        return x + y + z;
    };

    auto res = std::apply(add, std::tuple(1, 2, 3));

    std::cout << res << std::endl;

    return 0;
}