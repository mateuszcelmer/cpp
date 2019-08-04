#include <iostream>

using namespace std;

template <int N, int L = 1, int H = N>
struct Sqrt
{
    enum
    {
        mid = (L + H + 1) / 2
    };
    enum
    {
        res = (mid * mid > N) ? (int)Sqrt<N, L, mid - 1>::res : (int)Sqrt<N, mid, H>::res
    };
};
template <int N, int L>
struct Sqrt<N, L, L>
{
    enum
    {
        res = L
    };
};

int main()
{
    std::cout << Sqrt<144>::res << std::endl;
    return 0;
}