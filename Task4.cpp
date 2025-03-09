#include"iostream"
#include"string"
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    int marks[5];
};

int input(Student *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Student Name : ";
        cin >> (arr + i)->name;
        cout << "Enter Student ID : ";
        cin >> (arr + i)->rollNumber;
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter Marks for Subject " << j + 1 << " : ";
            cin >> arr[i].marks[j];
        }
        cout << endl;
    }
    return 0;
}

int grades(Student *arr, int size) {
    for (int i = 0; i < size; i++ ) {
        int total = 0;
        for (int j = 0; j < 5; j++)
        {
            total += arr[i].marks[j];
        }
        cout << "The Average Marks of Student " << i + 1 << " are : " << total / 5 << endl;
        if (total/5 >= 90)
        {
            cout << "Grade : A" << endl;
        }
        else if (total/5 >= 80)
        {
            cout << "Grade : B" << endl;
        }
        else if (total/5 >= 70) 
        {
            cout << "Grade : C" << endl;
        }
        else{
            cout << "Grade : D" << endl;
        } 
    }
    return 0;
}

int main() {
    int size;
    cout << "Enter Number of Students : ";
    cin >> size;
    Student *students = new Student[size];
    input(students, size);
    grades(students, size);

    return 0;
}