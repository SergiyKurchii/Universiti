#include <iostream>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Перемістити елементи arr[0..i-1], які більші за ключ
        // на одну позицію попереду поточної позиції
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Створення масиву
    int arr[] = {80, 20, 60, 10, 50, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Виведення початкового масиву
    std::cout << "Initial array: ";
    printArray(arr, size);

    // Сортування бульбашкою
    bubbleSort(arr, size);
    std::cout << "Array after bubble sort: ";
    printArray(arr, size);

    // Створення нового масиву для сортування вставками
    int arrInsertion[] = {60, 20, 80, 10, 50, 30};

    // Виведення початкового масиву для сортування вставками
    std::cout << "Initial array for insertion sort: ";
    printArray(arrInsertion, size);

    // Сортування вставками
    insertionSort(arrInsertion, size);
    std::cout << "Array after insertion sort: ";
    printArray(arrInsertion, size);

    return 0;
}
