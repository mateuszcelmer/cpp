#include <iostream>

using namespace std;

int main()
{
    auto x = u8'x';
    std::cout << x << std::endl;

    for (int i = 0; i < 100; ++i)
    {
        x--;
        std::cout << x << ", ";
        if (!(i % 30))
            cout << endl;
    }

    return 0;
}