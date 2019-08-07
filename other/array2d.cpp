#include <iostream>

using namespace std;

int main()
{
    int arr[5][4] = {{1, 2, 3}, {3, 2, 1}, {4, 4, 4}, {0, 2, 3}, {2, 3, 4}};

    // 5 wskaźników
    std::cout << "" << std::endl;
    for (auto &&el : arr)
        std::cout << el << ", ";

    // wartości
    std::cout << "" << std::endl;
    for (auto &&el : arr)
    {
        for (auto &&e : el)
            std::cout << e << ", ";
        std::cout << "" << std::endl;
    }

    // new i delete
    int **arr2 = new int *[10];

    for (int i = 0; i < 10; i++)
        arr2[i] = new int[5];

    // wartości
    std::cout << "" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr2[i][j] = i + j;
            std::cout << arr2[i][j] << ", ";
        }
        std::cout << "" << std::endl;
    }

    std::cout << "" << std::endl;

    // delete
    for (int i = 0; i < 10; i++)
    {
        delete[] arr2[i];
    }
    return 0;
}