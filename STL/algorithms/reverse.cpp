#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    std::reverse(v.begin(), v.end());
    for (auto &&el : v)
        std::cout << el << ", ";

    std::cout << "" << std::endl;
    std::reverse(v.begin(), v.end());
    for (auto &&el : v)
        std::cout << el << ", ";

    std::cout << "" << std::endl;

    // reverse manually

    auto rptr = v.rbegin();

    for (auto it = v.begin(); it < v.begin() + v.size() / 2; ++it)
        std::swap(*it, *rptr++);

    for (auto &&el : v)
        std::cout << el << ", ";
    return 0;
}