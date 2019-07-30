#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string str1 = "1234567890";
    std::cout << "str1 " << str1 << std::endl;

    auto str2 = std::move(str1);
    std::cout << "str1 " << str1 << std::endl;
    std::cout << "str2 " << str2 << std::endl;
    return 0;
}