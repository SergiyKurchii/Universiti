#include <iostream>
#include <queue>

void mergeQueues(std::queue<int> &q1, std::queue<int> &q2)
{
    std::queue<int> result;

    while (!q1.empty() && !q2.empty())
    {
        if (q1.front() < q2.front())
        {
            result.push(q1.front());
            q1.pop();
        }
        else
        {
            result.push(q2.front());
            q2.pop();
        }
    }

    while (!q1.empty())
    {
        result.push(q1.front());
        q1.pop();
    }

    while (!q2.empty())
    {
        result.push(q2.front());
        q2.pop();
    }

    // Переносимо результат об'єднання у вихідну чергу q1
    q1 = result;
}

int main()
{
    std::queue<int> q1, q2;

    // Ініціалізація черг q1 та q2
    q1.push(2);
    q1.push(5);
    q1.push(8);

    q2.push(1);
    q2.push(3);
    q2.push(7);

    std::cout << "Quque q1: ";
    std::queue<int> tempQ1 = q1;
    while (!tempQ1.empty())
    {
        std::cout << tempQ1.front() << " ";
        tempQ1.pop();
    }
    std::cout << std::endl;

    std::cout << "Quque q2: ";
    std::queue<int> tempQ2 = q2;
    while (!tempQ2.empty())
    {
        std::cout << tempQ2.front() << " ";
        tempQ2.pop();
    }
    std::cout << std::endl;

    mergeQueues(q1, q2);

    // Виведення об'єднаної черги q1
    std::cout << "Combined queue: ";
    while (!q1.empty())
    {
        std::cout << q1.front() << " ";
        q1.pop();
    }

    return 0;
}
