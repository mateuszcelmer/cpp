#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> mapa_1;

    mapa_1.insert(pair<int, int>(1, 304));
    mapa_1.insert(pair<int, int>(2, 303));
    mapa_1.insert(pair<int, int>(3, 306));
    mapa_1.insert(pair<int, int>(4, 302));
    mapa_1.insert(pair<int, int>(7, 301));

    map<int, int>::iterator itr;
    for (itr = mapa_1.begin(); itr != mapa_1.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    map<int, int> mapa_2(mapa_1.begin(), mapa_1.end());

    for (itr = mapa_2.begin(); itr != mapa_2.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    cout << endl;

    mapa_2.erase(mapa_2.begin(), mapa_2.find(3));
    for (itr = mapa_2.begin(); itr != mapa_2.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }

    return 0;
}