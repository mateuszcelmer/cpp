#include <iostream>
#include <vector>

auto print = [](auto &v) {
    // print vector's content
    for (auto &el : v)
        std::cout << el << ", ";
    std::cout << "" << std::endl;
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(v);

    auto first = v.begin();
    auto result = v.begin();

    auto pred = [](int i) { return i % 2; };

    // remove_if
    while (first != v.end())
    {
        if (!pred(*first))
        {
            *result = std::move(*first);
            ++result;
        }
        ++first;
    }
    std::cout << "removed after: " << v.end() - result << std::endl;

    print(v);

    return 0;
}