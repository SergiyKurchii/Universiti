#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Функція для виведення масиву на екран
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функція для сортування масиву за методом бульбашки
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функція для знаходження ключа в середині лівої частини масиву
int findMiddleLeftKey(int arr[], int size)
{
    return arr[size / 4];
}

// Функція для бінарного пошуку ключа
int binarySearch(int arr[], int size, int key)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid; // Знайдено ключ
        }
        else if (arr[mid] < key)
        {
            left = mid + 1; // Пошук у правій частині
        }
        else
        {
            right = mid - 1; // Пошук у лівій частині
        }
    }

    return -1; // Ключ не знайдено
}

int main()
{
    const int K = 12;                       // Номер студента
    int N = static_cast<int>(20 - 0.6 * K); // Обчислення розміру масиву
    const int RANGE_MIN = 10;
    const int RANGE_MAX = 100;

    // Ініціалізація генератора випадкових чисел
    srand(time(nullptr));

    // Створення та заповнення масиву випадковими числами
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % (RANGE_MAX - RANGE_MIN + 1) + RANGE_MIN;
    }

    cout << "Initial array: ";
    printArray(arr, N);

    // Сортування масиву за методом бульбашки
    bubbleSort(arr, N);
    cout << "Sorted array: ";
    printArray(arr, N);

    // Знаходження ключа в середині лівої частини масиву
    int middleLeftKey = findMiddleLeftKey(arr, N);
    cout << "The key is in the middle of the left part: " << middleLeftKey << endl;

    // Бінарний пошук ключа
    int searchResult = binarySearch(arr, N, middleLeftKey);
    if (searchResult != -1)
    {
        cout << "The key is found in the position " << searchResult << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    return 0;
}
