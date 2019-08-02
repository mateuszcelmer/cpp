#include <iostream>

using namespace std;

int main()
{
    int a = 1;             // `a` is declared as type `int`
    decltype(a) b = a;     // `decltype(a)` is `int`
    const int &c = a;      // `c` is declared as type `const int&`
    decltype(c) d = a;     // `decltype(c)` is `const int&`
    decltype(123) e = 123; // `decltype(123)` is `int`
    int &&f = 1;           // `f` is declared as type `int&&`
    decltype(f) g = 1;     // `decltype(f) is `int&&`
    decltype((a)) h = g;   // `decltype((a))` is int&
    return 0;
}