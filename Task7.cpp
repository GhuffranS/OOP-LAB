#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - i - 1]);
    }
}

int main () {
    int size;
    cout << "Enter Size of Array : ";
    cin >> size;
    int *Number = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Item " << i + 1 << " : ";
        cin >> Number[i];
    }

    cout << "Original Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Number[i] << "\t";
    }
    cout << endl;

    cout << "Reversed Array" << endl;
    reverse(Number, size);
    for (int i = 0; i < size; i++)
    {
        cout << Number[i] << "\t";
    }

    delete[] Number;
    return 0;
}
