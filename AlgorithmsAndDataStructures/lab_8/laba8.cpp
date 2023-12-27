#include <iostream>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[(left + right) / 2];

    while (left <= right)
    {
        while (arr[left] < pivot)
        {
            left++;
        }

        while (arr[right] > pivot)
        {
            right--;
        }

        if (left <= right)
        {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    return left;
}

void quickSortHoare(int arr[], int start, int end)
{
    if (start < end)
    {
        int rightStart = partition(arr, start, end);
        quickSortHoare(arr, start, rightStart - 1);
        quickSortHoare(arr, rightStart, end);
    }
}

int main()
{
    const int size = 6;
    int arr[size] = {12, 7, 10, 5, 2, 4};

    std::cout << "Original array: ";
    printArray(arr, size);

    quickSortHoare(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
