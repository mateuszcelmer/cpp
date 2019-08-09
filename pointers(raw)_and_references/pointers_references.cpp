#include <iostream>

using namespace std;

using A = int;

int main()
{
    int *ptr = new A();
    std::cout << *ptr << std::endl;
    *ptr = 40;

    std::cout << *ptr << std::endl;
    return 0;
}