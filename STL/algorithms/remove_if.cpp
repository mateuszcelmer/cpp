#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::vector<int> vec{10, 9, 7, 4, 8, 5, 2, 0, 1};

    // auto x = std::remove_if(std::begin(vec), std::end(vec), [](auto const &el) { return el > 5; });
    // vs
    auto x = vec.erase(std::remove_if(std::begin(vec), std::end(vec), [](auto const &el) { return el > 5; }), std::end(vec));

    std::cout << "x = " << *x << std::endl;
    for (auto &&el : vec)
        std::cout << el << std::endl;
    return 0;
}