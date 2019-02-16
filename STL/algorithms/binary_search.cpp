#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void show(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

inline void show(vector<int>::iterator b, vector<int>::iterator e)
{
    while (b != e)
        cout << *b++ << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 8, 7, 10, 22, 44, 2, 4, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    show(arr, n);

    cout << "\nShuffle:\n";
    vector<int> vec(arr, arr + n);
    for (size_t i = 0; i < 10; i++)
    {
        random_shuffle(vec.begin(), vec.end());
        show(vec.begin(), vec.end());
    }

    cout << "\nIs sorted?:\n";
    cout << is_sorted(arr, arr + n) << endl;

    cout << "\nSort:\n";
    sort(arr, arr + n);
    show(arr, n);

    cout << "\nIs sorted?:\n";
    cout << is_sorted(arr, arr + n) << endl;

    cout << "\nBinary_search:\n";
    int x = 22;
    binary_search(arr, arr + n, x) ? cout << x << " found" << endl : cout << x << " not found" << endl;
    x = 33;
    binary_search(arr, arr + n, x) ? cout << x << " found" << endl : cout << x << " not found" << endl;

    return 0;
}