#include "iostream"
#include "string"
using namespace std;

int registration(string arr1[], string arr2[], int choice1, int choice2){

    
    for (int i = 0; i < choice1; i++)
    {
        cout << "Enter the name of participant " << i+1 << "\n";
        cin >> arr1[i];
    }
    
    for (int i = 0; i < choice2; i++)
    {
        cout << "Enter the name of participant " << i+1 << "\n";
        cin >> arr2[i];
    }

    for (int i = 0; i < choice1; i++)
    {
        cout << "The name of participant "<<i+1<<" of event 1 is "<<arr1[i]<<endl;
    }
    for (int i = 0; i < choice2; i++)
    {
        cout << "The name of participant "<<i+1<<" of event 2 is "<<arr2[i]<<endl;
    }
    return 0;
}

int attendanceCheck(string arr1[],string arr2[]){
    string name;
    cout << "Enter name to check : ";
    cin >> name;

    for (int i = 0; i < 5; i++)
    {
        if (name == arr1[i])
        {
            cout << name << " is present in event 1"<<endl;
            return 0;
        }
        
    }
    
    for (int i = 0; i < 5; i++)
    {
        if (name == arr2[i])
        {
            cout << name << " is present in event 2"<<endl;
            return 0;
        }
        
    }

    cout << name << " is not present for either event"<<endl;
    return 0;

}

int totalDonations(int participants1, int participants2){
    cout << "Total donations for event 1 : "<<participants1*10<<"$"<<endl;
    cout << "Total donations for event 2 : "<<participants2*10<<"$"<<endl;
    cout << "Total donations : "<<(participants1+participants2)*10<<"$"<<endl;
    return 0;
}

int displayReverse(string arr1[], string arr2[], int num1, int num2){
    for (int i = num1-1; i >= 0; i--)
    {
        cout << "Name of person " << i+1 << " for event 1 : "<<arr1[i]<<endl;
    }
    
    for (int i = num2-1; i >= 0; i--)
    {
        cout << "Name of person " << i+1 << " for event 2 : "<<arr2[i]<<endl;
    }
    return 0;
}

int popularityChart(int num1, int num2){
    cout <<"Event 1: ";
    for (int i = 0; i < num1; i++)
    {
        cout<<"*";
    }
    cout<<endl;
    cout<<"Event 2: ";
    for (int i = 0; i < num2; i++)
    {
        cout<<"*";

    }
    cout<<endl;
    return 0;
    
}




int main(){
    string event1[5];
    string event2[5];
    int choice1, choice2 = 0;

    cout<<"Enter the number of participants for event 1 : ";
    cin >> choice1;
    
    while (choice1 > 5)
    {
        cout << "Maximum number of participants is 5, Enter number less than or equal to 5"<<endl;
        cin >> choice1;
    }
    
    cout<<"Enter the number of participants for event 2 : ";
    cin >> choice2;
    
    while (choice2 > 5)
    {
        cout << "Maximum number of participants is 5, Enter number less than or equal to 5"<<endl;
        cin >> choice2;
    }
    
    registration(event1,event2,choice1,choice2);
    attendanceCheck(event1,event2);
    totalDonations(choice1,choice2);
    displayReverse(event1,event2,choice1,choice2);
    popularityChart(choice1,choice2);


    


}