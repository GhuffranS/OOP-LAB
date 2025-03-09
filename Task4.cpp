#include <iostream>
using namespace std;

class Laptop{
    public:
        string brand;
        string model;
        string processor;
        int ram; // In GBs
        int storage; // In GBs

        void turnOn(){
            cout << "Laptop Is On" << endl;
        }

        void turnOff(){
            cout << "Laptop is off" << endl;
        }

        void runProgram(string &programName){
            cout << "Program " << programName << " Has Been Started" << endl;
        }

        void specifications(){
            cout << "Brand Name : " << brand << endl;
            cout << "Laptop Model : " << model << endl;
            cout << "Processor : " << processor << endl;
            cout << "RAM : " << ram << " GBs" << endl;
            cout << "Storage : " << storage << " GBs" << endl;
        }
};

int main(){
    Laptop lap;
    lap.brand = "Dell";
    lap.model = "Latitude 7470";
    lap.processor = "i7 8th Gen";
    lap.ram = 16;
    lap.storage = 512;
    lap.specifications();
}