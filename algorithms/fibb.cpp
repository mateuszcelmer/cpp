#include <iostream>
#include <iterator>
#include <array>
#include <numeric>

using namespace std;

// recursive

int fib(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

// iterative

int fibb(int n)
{
    if (n <= 1)
        return 1;

    int n1 = 0, n2 = 1, res = 0;
    for (int i = 1; i < n; ++i)
    {
        res = n1 + n2;
        n1 = n2;
        n2 = res;
    }
    return res;
}

// compile-time

template<int N>
struct fibbb
{
    enum {
        val = fibbb<N-1>::val + fibbb<N-2>::val
    };
};

template<>
struct fibbb<2>
{
    enum {
        val = 1
    };
};
template<>
struct fibbb<1>
{
    enum {
        val = 1
    };
};

void fibbbb()
{
    // Fibonacci
 
    std::array<int, 10> a {1};
 
    adjacent_difference(begin(a), std::prev(end(a)), std::next(begin(a)), std::plus<> {});
 
    copy(begin(a), end(a), std::ostream_iterator<int> {std::cout, " "});
}

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << fib(i) << " : ";
        std::cout << fibb(i) << endl;
    }

    std::cout << fibbb<10>::val << std::endl;

    fibbbb();
    return 0;
}