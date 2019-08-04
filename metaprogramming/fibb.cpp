#include <iostream>

using namespace std;

template <int N>
struct Fibb
{
    enum
    {
        val = Fibb<N - 1>::val + Fibb<N - 2>::val
    };
};

template <>
struct Fibb<2>
{
    enum
    {
        val = 1
    };
};

template <>
struct Fibb<1>
{
    enum
    {
        val = 1
    };
};

int main()
{
    constexpr auto n = 30;
    std::cout << "Fibb " << n << " : " << Fibb<n>::val << std::endl;

    return 0;
}