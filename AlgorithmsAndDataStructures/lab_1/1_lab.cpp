#include <iostream>
#include <random>

using namespace std;

int main()
{

    // Create a 5x5 matrix with random elements from 1 to 100
    int matrix[5][5];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = dist(gen);
        }
    }

    // Create a dynamic array to store the elements of the upper triangle
    int *upper_triangle = new int[10];
    int upper_triangle_size = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 5; j++)
        {
            upper_triangle[upper_triangle_size] = matrix[i][j];
            upper_triangle_size++;
        }
    }

    // Display the matrix
    cout << "Matrix:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Display the upper triangle
    cout << "Upper triangle:" << endl;
    for (int i = 0; i < upper_triangle_size; i++)
    {
        cout << upper_triangle[i] << " ";
    }
    cout << endl;

    // Delete the dynamic array
    delete[] upper_triangle;

    return 0;
}
