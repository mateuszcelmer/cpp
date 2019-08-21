#include <iostream>

using namespace std;

int main()
{
    static_assert(std::is_same<int, int>::value);
    static_assert(std::is_integral<int>::value);

    return 0;
}