#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> flist1;
    forward_list<int> flist2;
    flist1.assign({9, 8, 7, 6, 5, 4});
    flist2.assign(10, 2);

    cout << "Elementy pierwszej f_listy: ";
    for (auto &&i : flist1)
        cout << i << " ";
    cout << endl;

    cout << "Elementy drugiej f_listy: ";
    for (auto &&i : flist2)
        cout << i << " ";
    cout << endl;

    cout << "flist1.remove_if([](int x) { return x > 7; });" << endl;
    flist1.remove_if([](int x) { return x > 7; });

    cout << "Elementy pierwszej f_listy: ";
    for (auto &&i : flist1)
        cout << i << " ";
    cout << endl;

    flist1.push_front(0);
    flist1.push_front(4);
    flist1.push_front(5);

    flist2.splice_after(++flist2.begin(), flist1);
    flist2.unique();
    flist2.reverse();

    cout << "Elementy drugiej f_listy: ";
    for (auto &&i : flist2)
        cout << i << " ";
    cout << endl;

    flist1.clear();

    flist1.empty() ? cout << "Lista 1 jest pusta\n" : cout << "Lista 1 nie jest pusta\n";
    flist2.empty() ? cout << "Lista 2 jest pusta\n" : cout << "Lista 2 nie jest pusta\n";

    return 0;
}