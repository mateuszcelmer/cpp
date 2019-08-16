#include <iostream>

using namespace std;

struct A
{
    int a;
    char b;
    int c;
    char d;
};

struct B
{
    char b;
    int a;
    int c;
    char d;
};

struct C
{
    char b;
    char d;
    int a;
    int c;
};

struct D
{
    int a;
    int c;
    char b;
    char d;
};

int main()
{
    std::cout << "sizeof(A) : " << sizeof(A) << std::endl;
    std::cout << "sizeof(B) : " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) : " << sizeof(C) << std::endl;
    std::cout << "sizeof(D) : " << sizeof(D) << std::endl;
    std::cout << "sizeof(int) : " << sizeof(int) << ", sizeof(char) : " << sizeof(char) << std::endl;
    return 0;
}