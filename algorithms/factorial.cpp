#include <numeric>
#include <algorithm>
#include <iostream>
#include <set>
#include <functional>

long fact(int n)
{
    if(n==1) return 1;
    return n * fact(n-1);
}

long fac(int n)
{
    long res = 1;
    for(int i=2; i<=n; ++i)
    {
        res*=i;
    }
    return res;
}

template<int N>
struct fa
{
    enum{
        val = fa<N-1>::val * N
    };
};

template<>
struct fa<1>
{
    enum{
        val = 1
    };
};

int main()
{
    std::cout << fact(4) << '\n';
    std::cout << fac(4) << '\n';
    std::cout << fa<4>::val << '\n';
}