#include <iostream>

using namespace std;

template <typename T>
void log(T first)
{
    cout << first << "";
}

template <typename T, typename... Args>
void log(T first, Args... args)
{
    cout << first << ", ";
    log(args...);
}

// The base case: we just have a single number.
template <typename T>
double sum(T t)
{
    return t;
}

// The recursive case: we take a number, alongside
// some other numbers, and produce their sum.
template <typename T, typename... Rest>
double sum(T t, Rest... rest)
{
    return t + sum(rest...);
}

int main()
{
    log(1, 3.14, "Hi there!", 0.9999999123, 12345, "Hello :-)"s);
    cout << "\nsum(1, 2, 3, 4, 5, 6): " << sum(1, 2, 3, 4, 5, 6) << endl;
    return 0;
}