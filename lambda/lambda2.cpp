#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// passing outer scope elements inside lambda functions

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int coef = 5;

    cout << "\noutside the scope coef = (" << coef << "), ";
    cout << "\n\nfor_each(begin(v), end(v), [](int x) {" << endl;
    for_each(begin(v), end(v), [](int x) {
        cout << x << " ( ), ";
        // cannot access: read or write coef
        // cout << "coef: " << coef << endl;
        // coef = 2;
    });

    cout << "\n\nfor_each(begin(v), end(v), [=](int x) {" << endl;
    for_each(begin(v), end(v), [=](int x) {
        cout << x << " ";
        cout << "(" << coef << "), ";
        // coef = 2; // cannot modify
    });

    cout << "\n\nfor_each(begin(v), end(v), [&](int x) {" << endl;
    for_each(begin(v), end(v), [&](int x) {
        cout << x << " ";
        coef = 2;
        cout << "(" << coef << "), ";
    });
    cout << "\n\noutside the scope coef = (" << coef << "), ";
    return 0;
}