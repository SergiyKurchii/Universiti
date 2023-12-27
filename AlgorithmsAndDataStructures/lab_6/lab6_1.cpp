#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 30;

void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 91 + 10; // Генерує випадкове число в діапазоні [10, 100]
    }
}

void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(0)));

    int A[ARRAY_SIZE];

    // Заповнення та вивід початкового масиву
    std::cout << "Initial array A:\n";
    fillArray(A, ARRAY_SIZE);
    printArray(A, ARRAY_SIZE);

    // Сортування та вивід відсортованого масиву
    insertionSort(A, ARRAY_SIZE);
    std::cout << "Array A after ascending sorting:\n";
    printArray(A, ARRAY_SIZE);

    return 0;
}
