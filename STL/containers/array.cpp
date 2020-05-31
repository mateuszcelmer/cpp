#include <iostream>
#include <array>
using namespace std;

int main()
{
    std::array<int, 10> arr = {1, 2, 3, 4};
    {
        for (auto it = arr.crbegin(); it != arr.crend(); ++it)
            std::cout << *it << ", ";
    }
    std::cout << std::endl;
    {
        for (int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i] << " ";
    }
    std::cout << std::endl;
    {
        for (auto& el : arr)
            cout << el << " ";
    }
    return 0;
}