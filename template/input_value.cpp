#include <iostream>

using namespace std;

template<int i>
void foo()
{
    std::cout << i << std::endl;
}

int main()
{
    foo<123>();
    return 0;
}