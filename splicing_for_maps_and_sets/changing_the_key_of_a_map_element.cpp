#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::map<int, string> m{{1, "one"}, {2, "two"}, {3, "three"}};
    auto e = m.extract(2);
    e.key() = 4;
    m.insert(std::move(e));

    std::cout << "\nmap:" << std::endl;
    for (auto &el : m)
        std::cout << "(" << el.first << ", " << el.second << "), " << std::endl;

    return 0;
}