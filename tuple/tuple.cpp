#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    tuple<int, double, string> test(3, 2.3, "Text");

    auto v1 = get<0>(test);
    auto v2 = get<1>(test);
    auto v3 = get<2>(test);

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    return 0;
}