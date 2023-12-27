#include <iostream>
#include <vector>

int main()
{
    int N, M;
    double c1, c2;
    std::cout << "Enter the dimensions of the array N and M: ";
    std::cin >> N >> M; // Зчитуємо розміри масиву
    std::cout << "Enter the values ​​of c1 and c2: ";
    std::cin >> c1 >> c2; // Зчитуємо значення інтервалу

    double **A = new double *[N]; // Створюємо двовимірний динамічний масив
    for (int i = 0; i < N; i++)
    {
        A[i] = new double[M]; // Створюємо новий рядок в масиві
    }

    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> A[i][j]; // Зчитуємо елемент масиву
        }
    }

    std::vector<double> dynamicArr; // Створюємо динамічний масив для елементів, які знаходяться за межами інтервалу
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] < c1 || A[i][j] > c2) // Перевіряємо, чи елемент знаходиться за межами інтервалу
            {
                dynamicArr.push_back(A[i][j]); // Додаємо елемент до динамічного масиву
            }
        }
    }

    std::cout << "Elements of the array that are to " << c1 << " and after " << c2 << ":\n";
    for (double val : dynamicArr)
    {
        std::cout << val << " "; // Виводимо елемент динамічного масиву
    }

    for (int i = 0; i < N; i++)
    {
        delete[] A[i];
    }
    delete[] A; // Звільняємо пам'ять, виділену для масиву

    return 0;
}