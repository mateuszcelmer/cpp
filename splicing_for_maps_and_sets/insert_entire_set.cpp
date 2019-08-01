#include <iostream>
#include <set>

using namespace std;

int main()
{
    std::set<int> src{1, 3, 5};
    std::set<int> dst{2, 4, 5};

    dst.merge(src);

    std::cout << "\nsrc:" << std::endl;
    for (auto &el : src)
        std::cout << "(" << el << "), " << std::endl;

    std::cout << "\ndst:" << std::endl;
    for (auto &el : dst)
        std::cout << "(" << el << "), " << std::endl;

    return 0;
}