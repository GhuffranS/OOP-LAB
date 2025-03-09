#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollNumber;
    int marks;
};

int main() {
    int size = 0;
    int highest = 0;
    int index = 0;
    cout << "Enter The Number of Students : " << endl;
    cin >> size;
    Student *students = new Student[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Student Name : ";
        cin >> students[i].name;
        cout << "Enter Students Marks : ";
        cin >> students[i].marks;
        cout << "Enter Student ID : ";
        cin >> students[i].rollNumber;
        if (students[i].marks > highest)
        {
            highest = students[i].marks;
            index = i;
        }
    }

    cout << "\nStudent With The Highest Marks\nStudent Name : " << students[index].name << endl;
    cout << "Student's Roll Number : " << students[index].rollNumber << endl;
    cout << "Marks : " << students[index].marks << endl;

    delete[] students;
    return 0;
}