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

bool is_int(const std::any &operand)
{
    return operand.type() == typeid(int);
}

bool is_char_ptr(const std::any &operand)
{
    try
    {
        any_cast<const char *>(operand);
        return true;
    }
    catch (const std::bad_any_cast &)
    {
        return false;
    }
}

bool is_string(const std::any &operand)
{
    return any_cast<std::string>(&operand);
}

int main()
{
    std::vector<std::any> v{5, 3.14, "Hello!@#$%^", S(), U()};

    v.push_back(L"wide");

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

    std::cout << "" << std::endl;
    std::cout << std::any_cast<int>(v[0]) << std::endl;
    std::cout << std::any_cast<double>(v[1]) << std::endl;
    std::cout << std::any_cast<const char *>(v[2]) << std::endl;

    std::cout << "" << std::endl
              << "is_int(v[0]) = " << is_int(v[0]) << std::endl
              << "is_int(v[1]) = " << is_int(v[1]) << std::endl
              << "is_char_ptr(v[1]) = " << is_char_ptr(v[1]) << std::endl
              << "is_char_ptr(v[2]) = " << is_char_ptr(v[2]) << std::endl
              << "is_string(v[3]) = " << is_string(v[3]) << std::endl;
    return 0;
}