#include <iostream>
using namespace std;

class Battery{
    private:
        string name;
        int capacity;
    public:
        Battery(string name, int capacity) : name(name), capacity(capacity) {}

        void displayDetails(){
            cout << "Battery Name : " << name << endl;
            cout << "Max Battery Capacity : " << capacity << " mAh" << endl;
        }

};

class Smartphone{
    private:
        string model;
        int serialNo;
        Battery battery;
    public:
        Smartphone(string model, int serialNo, Battery battery) : model(model), serialNo(serialNo), battery(battery) {}

        void displayDetails(){
            cout << "Mobile Model : " << model << endl;
            cout << "Mobile Serial No : " << serialNo << endl;
            battery.displayDetails();
        }
        
};

int main(){
    Battery battery1("Li-Ion Max", 5000);
    Smartphone samsung("Galaxy A50", 77834332, battery1);
    samsung.displayDetails();
}