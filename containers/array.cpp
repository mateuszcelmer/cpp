#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 10> arr = {1, 2, 3};
    for (int i = arr.size() - 1; i >= 0; i--)
        cout << arr[i] << " ";
    return 0;
}