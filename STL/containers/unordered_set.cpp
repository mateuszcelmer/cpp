#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    unordered_set<string> uset = {"one", "two", "three", "A", "b", "C"};

    uset.insert("two");
    uset.insert("one");

    for (auto i : uset)
        cout << i << endl;

    return 0;
}