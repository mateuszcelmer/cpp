#include <iostream>

using namespace std;

int main()
{
    auto identity = [](int n) constexpr { return n; };
    static_assert(identity(123) == 123);
    return 0;
}