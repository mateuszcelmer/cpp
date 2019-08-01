//C++14

#include <iostream>

using namespace std;

template <class T>
constexpr T pi = T(3.1415926535897932385);

template <class T>
constexpr T e = T(2.7182818284590452353);

int main()
{
    std::cout << pi<int> << std::endl
              << pi<float> << std::endl;
    return 0;
}