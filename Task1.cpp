#include <iostream>
#include <string>
using namespace std;

class MarkerPen{
    public:
        string name;
        string colour;
        int inkLevel;
        bool refilibility;

    void write(){
        inkLevel = inkLevel - 10;
    }
    int refill(){
        if (refilibility == true)
        {
            inkLevel = 100;
            return 1;
        }
        return 0;
        }
};

int main(){
    MarkerPen pen;
    pen.colour = "blue";
    pen.name = "Dollar";
    pen.inkLevel = 100;
    pen.refilibility = true;
    pen.write();
    pen.write();
    if (pen.refill() == 1)
    {
        cout << "Pen Refilled ";
    }

    return 0;
}