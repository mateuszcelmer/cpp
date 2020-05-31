#include <iostream>

using namespace std;

int main()
{
    // 1-D
    {
        int *arr1 = new int[20];
        delete[] arr1;
    }
    {
        int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    }

    // 2-D
    {
        int **arr1 = new int *[10];
        for (int i = 0; i < 10; ++i)
            arr1[i] = new int[10];

        arr1[5][5] = 5;
        std::cout << arr1[5][5] << std::endl;

        for (int i = 0; i < 10; ++i)
            delete[] arr1[i];
        delete[] arr1;
    }
    {
        int *arr2 = new int[10 * 10];

        arr2[4*4] = 4;
        std::cout << arr2[4*4] << std::endl;

        delete[] arr2;
    }
    return 0;
}