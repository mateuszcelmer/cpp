#include <iostream>

using namespace std;

int main()
{
    const int x = 0;
    auto x1 = x;           // int
    decltype(auto) x2 = x; // const int

    int y = 0;
    int &y1 = y;
    auto y2 = y1;           // int
    decltype(auto) y3 = y1; // int&

    int &&z = 0;
    auto z1 = std::move(z);           // int
    decltype(auto) z2 = std::move(z); // int&&

    return 0;
}