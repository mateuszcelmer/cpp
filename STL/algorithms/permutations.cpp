#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {1, 7, 24, 10, 34, 46, 77, 99, 3, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec(arr, arr + n), v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << "\t";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "\n50 Permutations:" << endl;

    vector<int> &ref = vec;
    vector<int> *ptr = &v;
    for (size_t i = 0; i < 50; i++)
    {
        next_permutation(ref.begin(), ref.end());
        for (auto it = ref.begin(); it != ref.end(); ++it)
            cout << *it << " ";
        cout << "\t";
        next_permutation(ptr->begin(), ptr->end());
        for (auto it = ptr->begin(); it != ptr->end(); ++it)
            cout << *it << " ";
        cout << endl;
    }

    cout << "\nDistance from first to max element: \n"
         << distance(vec.begin(), max_element(vec.begin(), vec.end())) << "\t"
         << distance(v.begin(), max_element(v.begin(), v.end())) << "\t";
    return 0;
}