#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Give a size of the array: ";
    cin >> n;
    int *arr = new (nothrow) int[n];

    if (arr == nullptr)
    {
        cout << "problem with memory allocation!";
        return -1;
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    delete[] arr;
    return 0;
}