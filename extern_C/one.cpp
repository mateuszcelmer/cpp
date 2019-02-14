#include <iostream>

extern void foo(int);

int main()
{
    std::cout << "Hello from c++" << std::endl;
    foo(12);
    return 0;
}