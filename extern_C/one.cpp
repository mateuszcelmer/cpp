#include <iostream>
// #include "two.h"

// pierwszy sposób
extern void foo(int);

int main()
{
    std::cout << "Hello from c++" << std::endl;
    foo(12);
    return 0;
}