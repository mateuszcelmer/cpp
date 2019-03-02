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
    vector<any> v{5, 3.14, "Hello!@#$%^", S(), U()};

    for (auto &&i : v)
        cout << i.type().name() << "\n";

    cout << any_cast<int>(v[0]) << endl;
    cout << any_cast<double>(v[1]) << endl;
    cout << any_cast<const char *>(v[2]) << endl;

    return 0;
}