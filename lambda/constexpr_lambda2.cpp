#include <iostream>

using namespace std;

int main()
{
    constexpr auto add = [](int x, int y) {
        auto L = [=]{return x;};
        auto R = [=]{return y;};
        return [=] {return L() + R();};
    };

    static_assert(add(1,2)() == 3);
    return 0;
}