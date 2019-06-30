#include <iostream>

using namespace std;

int main()
{
    const char name[] =
        "M. M. Celmer";         // name's type is const char[13]
    auto arr1 = name;           // arr1's type is const char*
    auto &arr2 = name;          // arr2's type is const char (&)[13]
                                //
    void someFunc(int, double); // someFunc is a function;
                                // type is void(int, double)
    auto func1 = someFunc;      // func1's type is
                                // void (*)(int, double)
    auto &func2 = someFunc;     // func2's type is
                                // void (&)(int, double)
    return 0;
}