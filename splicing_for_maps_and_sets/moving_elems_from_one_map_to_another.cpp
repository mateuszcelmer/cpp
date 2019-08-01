#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::map<int, string> src{{1, "one"}, {2, "two"}, {3, "buckle my shoe"}};
    std::map<int, string> dst{{3, "three"}};
    dst.insert(src.extract(src.find(1))); // Cheap remove and insert of { 1, "one" } from `src` to `dst`.
    dst.insert(src.extract(2));           // Cheap remove and insert of { 2, "two" } from `src` to `dst`.
    // dst == { { 1, "one" }, { 2, "two" }, { 3, "three" } };

    std::cout << "\nsrc:" << std::endl;
    for (auto &el : src)
        std::cout << "(" << el.first << ", " << el.second << "), " << std::endl;

    std::cout << "\ndst:" << std::endl;
    for (auto &el : dst)
        std::cout << "(" << el.first << ", " << el.second << "), " << std::endl;
    return 0;
}