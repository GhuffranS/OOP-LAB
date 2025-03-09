#include"iostream"
using namespace std;

int main(){
    int size;
    int sum = 0;
    int max = 0;
    float avg;
    cout << "Enter number of elements you want to enter : ";
    cin >> size;
    int* myArary = new int[size];
    for (int x = 0; x < size; x++){
        cout << "Enter Element " << x + 1 << " : ";
        cin >> *(myArary + x);
        sum += *(myArary + x);
        if(myArary[x] > max){
            max = myArary[x];
        }
    }
    avg = sum / size;
    cout << endl;
    cout << "Sum of All Values : " << sum << endl;
    cout << "Maximum Value Entered : " << max << endl;
    cout << "Average Value Entered : " << avg << endl;

    delete[] myArary;

    return 0;
}