#include <iostream>
#include <memory>

using namespace std;

int main()
{
    constexpr int ab =123;
    static_assert(ab == 123);



    auto x = 1;

    std::unique_ptr<int> ptr( new int {123});


    std::cout << x << std::endl;
    return 0;
}