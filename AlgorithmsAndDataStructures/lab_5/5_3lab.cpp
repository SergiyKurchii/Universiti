#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countOccurrences(TreeNode *root, int x)
{
    if (root == nullptr)
    {
        return 0;
    }

    int count = 0;
    if (root->data == x)
    {
        count++;
    }

    count += countOccurrences(root->left, x);
    count += countOccurrences(root->right, x);

    return count;
}

int main()
{
    // Ініціалізація бінарного дерева
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);

    int x; // Шуканий елемент
    std::cout << "Enter the item you are looking for: ";
    std::cin >> x;

    int occurrences = countOccurrences(root, x);

    std::cout << "Element " << x << " enters the tree " << occurrences << " times.\n";

    // Очищення пам'яті від бінарного дерева
    // Ваш код для видалення дерева може бути інший, залежно від конкретної реалізації.
    // У цьому прикладі я просто видаляю кожен вузол за допомогою delete.
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}