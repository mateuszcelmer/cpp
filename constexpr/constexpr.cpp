//C++14

#include <iostream>
#include <array>

using namespace std;

constexpr int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    constexpr int i = factorial(5); // 120 at compile-time
    std::array<int, i> arr;

    int y = 120;
    // std::array<int, y> arr; // ERROR

    std::cout << arr.size() << std::endl;

    return 0;
}