
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

inline double pow_int(double x, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; ++i)
        res *= x;
    return res;
};

template <int N>
inline double pow_int(double x)
{
    double res = 1.0;
    for (int i = 0; i < N; ++i)
        res *= x;
    return res;
};

template <int N>
inline double pow(double x) { return x * pow<N - 1>(x); }
template <>
inline double pow<0>(double x) { return 1.0; }

int main()
{
    const double pi = 3.1415926;
    const int n = 5;
    const int N = 100000000;
    const double X = (double)N;

    cout << pow_int(pi, 4) << endl;
    cout << pow_int<4>(pi) << endl;
    cout << pow<4>(pi) << endl;

    double z;
    clock_t start = clock();

    for (int i = 0; i < N; i++)
    {
        z = pow_int(pi + i / X, n);
    }

    clock_t stop1 = clock();

    std::cout << (stop1 - start) / (double)CLOCKS_PER_SEC << std::endl;

    start = clock();

    for (int i = 0; i < N; i++)
    {
        z = pow_int<n>(pi + i / X);
    }

    stop1 = clock();

    std::cout << (stop1 - start) / (double)CLOCKS_PER_SEC << std::endl;

    start = clock();

    for (int i = 0; i < N; i++)
    {
        z = pow<n>(pi + i / X);
    }

    stop1 = clock();

    std::cout << (stop1 - start) / (double)CLOCKS_PER_SEC << std::endl;
    return 0;
}