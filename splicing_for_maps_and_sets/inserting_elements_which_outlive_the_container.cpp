#include <iostream>
#include <set>

using namespace std;

auto elementFactory()
{
    std::set<int> s{1, 2, 3};
    s.emplace(9);
    std::cout << "\nset1:" << std::endl;
    for (auto &el : s)
        std::cout << "(" << el << "), " << std::endl;
    return s.extract(s.begin());
}

int main()
{
    std::set<int> s2{};
    s2.insert(elementFactory());

    std::cout << "\nset2:" << std::endl;
    for (auto &el : s2)
        std::cout << "(" << el << "), " << std::endl;

    return 0;
}