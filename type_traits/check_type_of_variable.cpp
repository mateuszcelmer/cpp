#include <iostream>
#include <tuple>
#include <cassert>

using namespace std;

template <typename T>
bool isIntegral(const T &t)
{
    return std::is_integral_v<T>;
}

int main()
{
    auto [x, y] = std::make_tuple("asd", 2);
    assert(isIntegral(y));

    return 0;
}