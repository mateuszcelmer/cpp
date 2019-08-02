#include <iostream>

using namespace std;

int main()
{
    constexpr int x = 0;
    constexpr int y = 1;
    static_assert(x == y, "x != y");
    return 0;
}