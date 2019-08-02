#include <iostream>

using namespace std;

int main()
{
    auto x = 1;

    auto a = [x]() mutable {
        x = 2;
        std::cout << x << std::endl;
    };

    a();

    std::cout << x << std::endl;
    return 0;
}