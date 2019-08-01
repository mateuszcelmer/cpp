#include <iostream>

using namespace std;

[[deprecated]] void old_method() {}

int main()
{
    old_method();
    std::cout << "abc" << std::endl;
    return 0;
}