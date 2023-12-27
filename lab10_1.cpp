#include <iostream>
#include <vector>

// Функція для пошуку першого входження підрядка P у тексті S
int findSubstring(const std::vector<int> &S, const std::vector<int> &P)
{
    int n = S.size(); // Довжина тексту
    int m = P.size(); // Довжина підрядка

    // Проходимо весь текст
    for (int i = 0; i <= n - m; ++i)
    {
        int j;

        // Порівнюємо кожен символ підрядка P з відповідним символом тексту S
        for (j = 0; j < m; ++j)
        {
            if (S[i + j] != P[j])
            {
                break; // Якщо знайдено неспівпадіння, виходимо з циклу
            }
        }

        // Якщо весь підрядок P співпадає з частиною тексту S, повертаємо позицію знайденого входження
        if (j == m)
        {
            return i;
        }
    }

    return -1; // Якщо збігів не знайдено
}

int main()
{
    // Приклад використання
    std::vector<int> S = {1, 2, 3, 4, 5, 2, 7, 8};
    std::vector<int> P = {2, 7};

    // Виклик функції пошуку підрядка
    int result = findSubstring(S, P);

    // Виведення результатів
    if (result != -1)
    {
        std::cout << "The first entry is found at the position " << result << std::endl;
    }
    else
    {
        std::cout << "No matches found" << std::endl;
    }

    return 0;
}
