#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

int main()
{
    std::string str = {"   123ABC Hi, Mr World! :-)   "};
    std::cout << str << std::endl;

    std::reverse(str.begin(), str.end());

    std::cout << str << std::endl;

    auto rptr = str.rbegin();

    for (auto it = str.begin(); it < str.begin() + str.size() / 2; ++it)
        std::swap(*it, *rptr++);

    std::cout << str << std::endl;

    //lambda
    auto reverse = [](std::string &str) {
        auto rptr = str.rbegin();
        for (auto it = str.begin(); it < str.begin() + str.size() / 2; ++it)
            std::swap(*it, *rptr++);
    };

    reverse(str);
    std::cout << str << std::endl;

    return 0;
}