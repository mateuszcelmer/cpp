#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    auto upv = std::make_unique<std::vector<int>>(5, 30);
    (*upv).push_back(10);
    for (auto &&i : *upv)
    {
        std::cout << i << std::endl;
    }

    upv = std::unique_ptr<std::vector<int>>(new std::vector<int>{1, 2, 3, 4, 5, 6});
    (*upv).push_back(10);
    for (auto &&i : *upv)
    {
        std::cout << i << std::endl;
    }

    auto upi(std::make_unique<int>(2));

    auto initList = {10, 20};
    auto spv = std::make_shared<std::vector<int>>(initList);

    return 0;
}