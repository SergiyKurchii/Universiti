#include <iostream>

int main() {
    int array[5][4] = {
        {14, 0, 1, 10},
        {0, 1, 0, 1},
        {1, 2, 0, 9},
        {7, 4, 1, 1},
        {1, 15, 22, 1}
    };

    int count = 0;
    int sum = 0;

    // Виведення масиву
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << '\n';
    }
    // Підрахунок суми і кількості елементів рівних 1
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (array[i][j] == 1) {
                sum += array[i][j];
                count++;
            }
        }
    }

    std::cout << "The sum of the elements is equal to 1: " << sum << std::endl;
    std::cout << "The number of elements is equal to 1: " << count << std::endl;

    return 0;
}
