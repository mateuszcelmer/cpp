#include <iostream>

using namespace std;

int main()
{
    auto lamb = [value = []() { return 3; }()]() { return value * 2; };

    std::cout << lamb() << std::endl;

    return 0;
}