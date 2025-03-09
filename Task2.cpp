#include <iostream>
using namespace std;

class TeaMug{
    public:
        string brand;
        string colour;
        int capacity;
        int currentFillLevel;

        void siptea(){
            capacity -= 4;
        }
        int mugRefill(){
            if (currentFillLevel == 0)
            {
                currentFillLevel = capacity;
                return 1;
            }
            else{
                cout << "Mug is not empty" << endl;
                return 0;
            }
        }
};

int main(){
    TeaMug mug;
    mug.brand = "ikea";
    mug.colour = "black";
    mug.capacity = 200;
    mug.currentFillLevel = 120;
    mug.siptea();
    mug.siptea();
    mug.mugRefill();
    return 0;
}