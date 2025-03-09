#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> *(*(matrix + i) + j);
        }
    }
}

int** transposeMatrix(int** matrix, int rows, int cols) {
    int** transposed = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(transposed + j) + i) = *(*(matrix + i) + j);
        }
    }
    return transposed;
}

void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int** matrix = allocateMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);

    cout << "Original ";
    displayMatrix(matrix, rows, cols);

    int** transposedMatrix = transposeMatrix(matrix, rows, cols);
    cout << "Transposed ";
    displayMatrix(transposedMatrix, cols, rows);

    deallocateMatrix(matrix, rows);
    deallocateMatrix(transposedMatrix, cols);

    return 0;
}
