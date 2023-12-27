#include <iostream>

// Функція для обчислення середнього гармонічного
double harmonicMeanRecursive(int arr[], int n, int currentIndex = 0, double sum = 0)
{
    // Базовий випадок: якщо досягли кінця масиву
    if (currentIndex == n)
    {
        if (sum == 0)
        {
            // Уникнути ділення на нуль, якщо сума 0
            return 0;
        }
        else
        {
            return static_cast<double>(n) / sum;
        }
    }

    // Рекурсивний виклик для обчислення суми обернених значень
    double reciprocal = 1.0 / arr[currentIndex];
    return harmonicMeanRecursive(arr, n, currentIndex + 1, sum + reciprocal);
}

int main()
{
    int n;
    std::cout << "Enter size arr: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter elements arr: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    double harmonicMean = harmonicMeanRecursive(arr, n);

    std::cout << "harmonic Mean: " << harmonicMean << std::endl;

    return 0;
}