#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "abc";
    string b("abc");
    string c = {"abc"};
    string d{"abc"};

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    return 0;
}