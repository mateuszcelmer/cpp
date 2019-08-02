#include <iostream>

using namespace std;

template <typename... T>
struct arity
{
    constexpr static int value = sizeof...(T);
};

int main()
{
    static_assert(arity<>::value == 0);
    static_assert(arity<char, int, short>::value == 3);
    return 0;
}