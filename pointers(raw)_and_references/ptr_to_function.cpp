#include <iostream>

using namespace std;

int *foo() { return new int{2}; }

int main()
{
    int *(*bar)(void) = &foo;
    auto res = (*bar)();
    std::cout << *res << std::endl;
    return 0;
}