#include <iostream>

using namespace std;

int sum(const std::initializer_list<int> &list)
{
    int total = 0;
    for (auto &e : list)
    {
        total += e;
    }

    return total;
}

int main()
{
    auto list = {1, 2, 3, 4};
    cout << sum(list) << endl;
    cout << sum({1, 2, 3}) << endl;
    cout << sum({}) << endl;

    return 0;
}