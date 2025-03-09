#include "iostream"
#include "cstring"

using namespace std;

int main() {
    char *string1 = new char[100];
    char *string2 = new char[100];

    cout << "Enter First String : ";
    cin.getline(string1, 100);
    cout << "Enter Second String : ";
    cin.getline(string2, 100);

    int len1 = strlen(string1);
    int len2 = strlen(string2);
    char *concatenate = new char[len1 + len2 + 1];
    strcpy(concatenate, string1);
    strcat(concatenate, string2);
    cout << endl;

    if (strcmp(string1,string2) != 0) {
        cout << "Strings are not equal " << endl;
    }
    else {
        cout << "Strings are equal" << endl;
    }
    cout << endl;

    cout << "Length of string 1 : " << strlen(string1) << endl;
    cout << "Length of string 2 : " << strlen(string2) << endl;
    cout << "Length of concatenated string : " << strlen(concatenate) << endl;
    cout << endl;

    cout << "Concatenated String : " << concatenate << endl;

    delete[] string1;
    delete[] string2;
    delete[] concatenate;
    return 0;
}