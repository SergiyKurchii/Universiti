#include <iostream>

bool isCorrectString(const std::string &str)
{
    const int n = str.length();
    char stack[n];
    int top = -1; // Індекс вершини стека

    for (int i = 0; i < n; ++i)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch; // Додаємо в стек
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1)
            {
                return false; // Закриваюча дужка без відповідної відкриваючої
            }

            char openBracket = stack[top--];

            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '['))
            {
                return false; // Невідповідні відкриваюча і закриваюча дужки
            }
        }
    }

    return top == -1; // Всі відкриваючі дужки мають відповідні закриваючі
}

int main()
{
    std::string input;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    if (isCorrectString(input))
    {
        std::cout << "The string is valid.\n";
    }
    else
    {
        std::cout << "The string is not valid.\n";
    }

    return 0;
}
