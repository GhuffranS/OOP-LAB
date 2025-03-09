#include"iostream"
using namespace std;

struct Employee
{
    int employeeID;
    string name;
    string department;
    float salary;
};

int search(Employee *arr, int size,int id) {
    for (int i = 0; i < size; i++) {
        if ((arr+i)->employeeID == id) {
            cout << "Employee Found" << endl;
            return 0;
        }
    }
    cout << "Employee Not Found" << endl;
    return 0;
}

int data(Employee *arr, int num){
    for (int i = 0; i < num; i++)
    {
        cout << "Enter Employee ID For Employee " << i + 1 << " : ";
        cin >> (arr + i)->employeeID;
        cout << "Enter Name For Employee " << i + 1 << " : ";
        cin >> (arr + i)->name;
        cout << "Enter Department For Employee " << i + 1 << " : ";
        cin >> (arr + i)->department;
        cout << "Enter Salary For Employee " << i + 1 << " : ";
        cin >> (arr + i)->salary;
        
    }
    return 0;
}

int display(Employee *arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout << "Employee Number " << i + 1 << endl;
        cout << "Department ID : " << (arr + i)->department << endl;
        cout << "Employee ID : " << (arr + i)->employeeID << endl;
        cout << "Employee Name : " << (arr + i)->name << endl;
        cout << "Employee Salary : " << (arr + i)->salary << endl;
    }
    return 0;
}



int main() {
    int size;
    cout << "Enter number of employees you want to add : ";
    cin >> size;
    Employee *emp = new Employee[size];

    data(emp, size);
    display(emp, size);
    search(emp, size, 880);
}

