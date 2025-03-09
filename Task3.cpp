#include <iostream>
using namespace std;

class Planner{
    public:
        string tasks[12][30];
        Planner(){
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    tasks[i][j] = "";
                }
            }
        }
        void addTask(int month, int day, string &task){
            if (tasks[month-1][day-1] != "")
            {
                cout << "Task Already Present" << endl;
                return;
            }
            else{
                tasks[month-1][day-1] = task;
                cout << "Task Added Successfully" << endl;
                return;
            }
        }

        void deleteTask(int month, int day){
            if (tasks[month-1][day-1] != "")
            {
                tasks[month - 1][day - 1] = "";
                cout << "Task Removed Successfully" << endl;
                return;
            }
            else{
                cout << "No Task Present" << endl;
                return;
            }
        }

        void displayTasks(){
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 30; j++)
                {
                    if (tasks[i][j] != "")
                    {
                        cout << "Day : " << j + 1 << " Month : " << i + 1 << " Task : " << tasks[i][j] << endl;
                    }
                }
            }
            return;
        }
};

int main(){
    int month, day;
    int choice = 0;
    string task;
    Planner plan;
    while (choice != 4)
    {
        cout << "Enter Your Choice\n1. Add Task\n2. Delete Task\n3. Display All Tasks\n4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Month : ";
            cin >> month;
            cout << "Enter Day : ";
            cin >> day;
            cout << "Enter Task : ";
            cin >> task;
            plan.addTask(month, day, task);
            break;
        case 2:
            cout << "Enter Month : ";
            cin >> month;
            cout << "Enter Day : ";
            cin >> day;
            plan.deleteTask(month, day);
            break;
        case 3:
            plan.displayTasks();
            break;
        case 4:
            break;
        default:
            break;
        }
    }

    return 0;
}