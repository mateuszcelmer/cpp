/*
        g++ -std=c++17 any.cpp 
        ./a.out | c++filt -t
*/

#include <iostream>
#include <vector>
#include <string>
#include <any>

using namespace std;

struct S
{
    int a = 3;
    float b = 14.0982;
};

union U {
    int a = 10;
    double d;
};

int main()
{
    std::vector<std::any> v{5, 3.14, "Hello!@#$%^", S(), U()};

    for (auto &&i : v)
        std::cout << i.type().name() << "\n";

    for (auto &&i : v)
    {
        if (i.type() == typeid(int))
            std::cout << "int detected: " << std::any_cast<int>(i) << "\n";
        if (i.type() == typeid(double))
            std::cout << "double detected: " << std::any_cast<double>(i) << "\n";
        if (i.type() == typeid(const char *))
            std::cout << "const char * detected: " << std::any_cast<const char *>(i) << "\n";
    }

    std::cout << std::any_cast<int>(v[0]) << std::endl;
    std::cout << std::any_cast<double>(v[1]) << std::endl;
    std::cout << std::any_cast<const char *>(v[2]) << std::endl;

    return 0;
}