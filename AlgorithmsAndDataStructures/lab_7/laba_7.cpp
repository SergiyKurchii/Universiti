#include <iostream>

void shellSort(int arr[], int n)
{
    for (int step = n / 2; step > 0; step /= 2)
    {
        for (int i = step; i < n; ++i)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= step && arr[j - step] > temp; j -= step)
            {
                arr[j] = arr[j - step];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    const int size = 6;
    int arr[size] = {10, 5, 1, 11, 8, 9};

    std::cout << "Original array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    shellSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
