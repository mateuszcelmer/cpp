#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

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

    std::cout << "---" << std::endl;

    // C style array
    int arr[] = {1, 2, 3, 4};
    auto limit = remove_if(begin(arr), end(arr), [](int el) { return el % 2; });

    for (auto el : arr)     // print all
        std::cout << el << std::endl;

    return 0;
}