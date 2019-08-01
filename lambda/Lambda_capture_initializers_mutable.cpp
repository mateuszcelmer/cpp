#include <iostream>

using namespace std;

int main()
{
    auto generator = [x = 0]() mutable {
        // this would not compile without 'mutable' as we are modifying x on each call
        return x++;
    };

    std::cout << generator() << std::endl;
    std::cout << generator() << std::endl;
    std::cout << generator() << std::endl;
    std::cout << generator() << std::endl;
    std::cout << generator() << std::endl;

    return 0;
}