#include <iostream>

int main()
{
    unsigned short i = 0;

    while (--i >= 0) // infinite loop
    {
        std::cout << "i = " << i << std::endl;
    }
    return 0;
}