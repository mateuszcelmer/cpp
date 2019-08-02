#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    std::array<int, 4> a = {5, 2, 3, 4};
    std::sort(std::begin(a), std::end(a));
    std::reverse(std::begin(a), std::end(a));
    for (auto &el : a)
        el *= 2;
    for (auto &el : a)
        std::cout << el << std::endl;
    return 0;
}