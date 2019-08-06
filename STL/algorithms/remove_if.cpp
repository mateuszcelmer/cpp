#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> vec{10, 9, 7, 4, 8, 6, 2, 0, 1};
    auto vec2{vec};

    auto x = std::remove_if(std::begin(vec), std::end(vec), [](auto const &el) { return el > 5; });
    std::cout << "*x = " << *x << ", x-std::begin(vec) = " << x - std::begin(vec) << std::endl;
    for (auto &&el : vec)
        std::cout << el << ", ";

    // vs

    auto y = vec2.erase(std::remove_if(std::begin(vec2), std::end(vec2), [](auto const &el) { return el > 5; }), std::end(vec2));

    std::cout << "\n-" << std::endl;
    std::cout << "*y = " << *y << ", y-std::begin(vec2) = " << y - std::begin(vec2) << std::endl;
    for (auto &&el : vec2)
        std::cout << el << ", ";
    return 0;
}