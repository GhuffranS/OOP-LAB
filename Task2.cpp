#include "iostream"
using namespace std;

int main(){
    int rows, cols;
    cout << "Rows : ";
    cin >> rows;
    cout << "Columns : ";
    cin >> cols;

    int **matrix1 = new int *[rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix1[i] = new int[cols];
    }

    int **matrix2 = new int *[rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix2[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element for row " << i + 1 << ", Column " << j + 1 << " : ";
            cin >> matrix1[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element for row " << i + 1 << ", Column " << j + 1 << " : ";
            cin >> matrix2[i][j];
        }
    }

    cout << "Result of Addition of both matrices " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] + matrix2[i][j] << "   ";
        }
        cout << endl;
    }

    cout << "Result of subtraction of both matrices" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix1[i][j] - matrix2[i][j] << "   ";
        }
        cout << endl;
    }
    int** result = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        result[i] = new int[cols]; 
    }
    
    cout << "Result of Multiplication of both matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = 0; 
            for (int k = 0; k < cols; ++k) { 
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    

    for (int i = 0; i < rows; i++) {
        delete[] matrix1[i];
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    matrix1 = NULL;
    matrix2 = NULL;
}