#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "konstr" << std::endl;
    }
    ~A()
    {
        std::cout << "destr" << std::endl;
    }
};

int main()
{
    // auto ptr = new A;
    // delete ptr;

    auto ptr = (A*)malloc(sizeof(A));
    free(ptr);

    return 0;
}