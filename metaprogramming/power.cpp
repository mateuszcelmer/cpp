#include <iostream>

using namespace std;

template <int N, int K>
struct Pow
{
    enum
    {
        val = N * Pow<N, K - 1>::val
    };
};

template <int N>
struct Pow<N, 0>
{
    enum
    {
        val = 1
    };
};

int main()
{
    cout << Pow<2, 10>::val << endl;
    return 0;
}