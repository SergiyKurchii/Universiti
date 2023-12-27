// Включення необхідних заголовочних файлів
#include <iostream> // Для виведення результатів у консоль
#include <vector>   // Для використання векторів

// Функція для побудови таблиці префіксів-суфіксів (LPS)
std::vector<int> buildLPS(const std::string &pattern)
{
    int m = pattern.length();   // Довжина паттерна
    std::vector<int> lps(m, 0); // Ініціалізація таблиці LPS нулями
    int len = 0;                // Довжина поточного префіксу-суфіксу
    int i = 1;                  // Індекс для перегляду паттерна, починаючи з другого символу

    while (i < m)
    {
        // Перевірка, чи символ поточного індексу в паттерні збігається з попереднім символом
        if (pattern[i] == pattern[len])
        {
            len++;        // Збільшення довжини поточного префіксу-суфіксу
            lps[i] = len; // Зберігання довжини в таблиці LPS
            i++;          // Перехід до наступного символу паттерна
        }
        else
        {
            // Якщо символи не збігаються
            if (len != 0)
            {
                len = lps[len - 1]; // "Зсув" префіксу-суфіксу назад
            }
            else
            {
                lps[i] = 0; // Якщо довжина поточного префіксу-суфіксу 0, зберігаємо 0
                i++;        // Перехід до наступного символу паттерна
            }
        }
    }

    return lps; // Повертаємо побудовану таблицю LPS
}

// Функція для пошуку підрядка (паттерна) в тексті за допомогою алгоритму КМП
int KMPSearch(const std::string &text, const std::string &pattern)
{
    int n = text.length();    // Довжина тексту
    int m = pattern.length(); // Довжина паттерна

    std::vector<int> lps = buildLPS(pattern); // Побудова таблиці LPS

    int i = 0; // Індекс для тексту
    int j = 0; // Індекс для паттерна

    while (i < n)
    {
        // Порівнюємо символи тексту та паттерна
        if (pattern[j] == text[i])
        {
            i++; // Збільшуємо індекс для тексту
            j++; // Збільшуємо індекс для паттерна
        }

        // Якщо весь паттерн збіг, повертаємо позицію знайденого входження
        if (j == m)
        {
            return i - j;
        }
        // Якщо символи не збігаються, використовуємо інформацію з таблиці LPS для зсуву паттерна
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // Зсув паттерна
            }
            else
            {
                i++; // Зсув тексту
            }
        }
    }

    return -1; // Паттерн не знайдено
}

// Головна функція
int main()
{
    // Приклад використання
    std::string text = "I have a great day today";
    std::string pattern = "day";

    // Виклик функції пошуку підрядка
    int result = KMPSearch(text, pattern);

    // Виведення результатів
    if (result != -1)
    {
        std::cout << "The first occurrence of the pattern is found at position " << result << std::endl;
    }
    else
    {
        std::cout << "Pattern not found in text" << std::endl;
    }

    return 0;
}
