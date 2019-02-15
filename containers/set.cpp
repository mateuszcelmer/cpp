#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int, greater<int>> s;
    s.insert(10);
    s.insert(10);
    s.insert(10);
    s.insert(11);
    s.insert(12);
    s.insert(12);
    s.insert(13);

    set<int, greater<int>>::iterator it;
    for (it = s.begin(); it != s.end(); ++it)
        cout << '\t' << *it;

    return 0;
}