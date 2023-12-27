#include <iostream>

// Визначення структури Node для однозв'язного списку
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

// Функція для додавання нового вузла з заданою значенням в кінець списку
void append(Node *&head, int val)
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

// Функція для додавання нового вузла з заданою значенням на початок списку
void prepend(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Функція для вставки нового вузла з заданою значенням після певного вузла
void insertAfter(Node *node, int val)
{
    if (node == nullptr)
    {
        std::cout << "Error: Cannot insert after null pointer." << std::endl;
        return;
    }
    Node *newNode = new Node(val);
    newNode->next = node->next;
    node->next = newNode;
}

// Функція для видалення першого вузла з заданим значенням із списку
void deleteNode(Node *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *current = head;
    while (current->next)
    {
        if (current->next->data == val)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

// Функція для пошуку вузла із заданим значенням у списку
Node *search(Node *head, int val)
{
    Node *current = head;
    while (current)
    {
        if (current->data == val)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Функція для виведення елементів списку
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
    // Ініціалізація трьох однозв'язних списків: list1, list2 та result
    Node *list1 = nullptr;
    Node *list2 = nullptr;

    std::cout << "Enter 4 items for the first list:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        int val;
        std::cin >> val;
        append(list1, val);
    }

    std::cout << "Enter 4 items for the second list:" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        int val;
        std::cin >> val;
        append(list2, val);
    }

    Node *result = nullptr;
    Node *current1 = list1;
    Node *current2 = list2;

    // Копіювати перші 3 елементи з першого списку в результат
    for (int i = 0; i < 3; i++)
    {
        append(result, current1->data);
        current1 = current1->next;
    }

    // Копіювати перші 3 елементи з другого списку в результат
    for (int i = 0; i < 3; i++)
    {
        append(result, current2->data);
        current2 = current2->next;
    }

    std::cout << "List results:" << std::endl;
    printList(result);

    // Звільнити виділену пам'ять, видаливши всі три списки
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
