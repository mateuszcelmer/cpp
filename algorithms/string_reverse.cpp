#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void foo(std::string &str)
{
    std::reverse(str.begin(), str.end());
}

void foo(char *str, int n)
{
    std::reverse(str, str + n);
}

void bar(char *str, int n)
{
    for (int i = 0; i < n / 2; ++i)
    {
        std::swap(str[i], str[n - 1 - i]);
    }
}

void rab(char *str, int n)
{
    char &tmp = str[n];
    for (int i = 0; i < n / 2; ++i)
    {
        tmp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = tmp;
    }
    tmp='\0';
}

int main()
{
    // std::string
    std::string a{"ABC"};
    foo(a);
    std::cout << a << std::endl;

    // char[]
    char b[]{"123"};
    auto length = sizeof(b) / sizeof(char) - 1;
    foo(b, length);
    std::cout << b << std::endl;

    // char[]
    char c[]{"QWERTY"};
    bar(c, sizeof(c) / sizeof(char) - 1);
    std::cout << c << std::endl;

    // char[]
    char d[]{"NOKIA"};
    rab(d, sizeof(d) / sizeof(char) - 1);
    std::cout << d << std::endl;

    return 0;
}