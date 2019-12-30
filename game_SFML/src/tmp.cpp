#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    auto print = [](auto &cont) {
        for (auto &el : cont)
            std::cout << el.first << ", " << el.second << ", " << &el << std::endl;
    };

    std::unordered_multimap<std::string, int>
        tmp{
            {"abc", 1},
            {"abc", 4},
            {"abc", 5},
            {"q", 1},
            {"r", 1},
            {"t", 1},
        };

    std::unordered_multimap<std::string, int> map;

    std::cout << "begin: " << &*(map.begin()) << std::endl;

    map.insert(tmp.begin(), tmp.end());

    print(map);

    std::cout << "begin: " << &*(map.begin()) << std::endl;

    map.emplace("abc", 3);
    map.insert({"e", 3});

    print(map);
    std::cout << "begin: " << &*(map.begin()) << std::endl;

    return 0;
}