#include <iostream>

struct Node
{
    char data;
    Node *next;

    Node(char val) : data(val), next(nullptr) {}
};

void append(Node *&head, char val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *list1 = nullptr;
    Node *list2 = nullptr;

    std::cout << "Enter the characters for the first list (enter 0 to complete the entry):" << std::endl;
    char input1;
    while (std::cin >> input1 && input1 != '0')
    {
        if (islower(input1))
        {
            append(list1, input1);
        }
    }

    std::cout << "Enter the characters for the second list (enter 0 to complete the entry):" << std::endl;
    char input2;
    while (std::cin >> input2 && input2 != '0')
    {
        if (islower(input2))
        {
            append(list2, input2);
        }
    }

    Node *result = nullptr;
    Node *current1 = list1;
    Node *current2 = list2;

    // Додаємо символи нижнього регістра з перших двох списків до результату
    while (current1)
    {
        append(result, current1->data);
        current1 = current1->next;
    }

    while (current2)
    {
        append(result, current2->data);
        current2 = current2->next;
    }

    std::cout << "The resulting list:" << std::endl;
    printList(result);

    // Очищення пам'яті
    while (list1)
    {
        Node *temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2)
    {
        Node *temp = list2;
        list2 = list2->next;
        delete temp;
    }

    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
