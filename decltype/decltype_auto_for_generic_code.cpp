#include <iostream>

using namespace std;

// return type is int
auto f(const int &i)
{
    return i;
}

// return type is const int&
decltype(auto) g(const int &i)
{
    return i;
}

int main()
{
    int x = 123;
    static_assert(std::is_same<const int &, decltype(f(x))>::value == 0);
    static_assert(std::is_same<int, decltype(f(x))>::value == 1);
    static_assert(std::is_same<const int &, decltype(g(x))>::value == 1);
    return 0;
}