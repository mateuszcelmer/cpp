#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    // Time complexity of
    // map operations is O(Log n)
    // while for
    // unordered_set, it is O(1) on average.

    unordered_map<string, int> umap;

    umap["Lemur"] = 33;
    umap["Koczkodan"] = 99;
    umap["Manat"] = 320;
    umap["Pawian"] = 999;

    umap.insert(make_pair("Tygrys", 13));

    for (auto &&i : umap)
    {
        cout << i.first << " " << i.second << endl;
    }

    if (umap.find("Manat") == umap.end())
        cout << "Manat not found\n"
             << endl;
    else
        cout << "Manat found\n"
             << endl;

    unordered_map<string, int>::iterator it;

    for (it = umap.begin(); it != umap.end(); ++it)
        cout << it->first << " " << it->second << endl;

    return 0;
}