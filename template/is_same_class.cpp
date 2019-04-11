#include <iostream>

using namespace std;

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};

template <class A, class B>
bool IsSameClass()
{
    return is_same<A, B>::value;
};

int main()
{
    return 0;
}