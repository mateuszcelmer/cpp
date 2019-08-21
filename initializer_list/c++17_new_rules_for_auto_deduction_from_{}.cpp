#include <iostream>

using namespace std;

int main()
{
    auto a{1};    // int
    auto b = {1}; // initializer_list

    std::cout << a << std::endl;
    // std::cout << b << std::endl;  // error!
    return 0;
}