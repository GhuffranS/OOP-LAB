#include <iostream>
using namespace std;

class Account {
    private:
        int accountNumber;
        float balance;
    public:
        Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

        void displayDetails() {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingsAccount : public Account {
    private:
        float interestRate;
    public:
        SavingsAccount(int accountNumber, float balance, float interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "Interest Rate: " << interestRate << endl;
        }
};

class CheckingAccount : public Account {
    private:
        float overdrawLimit;
    public:
        CheckingAccount(int accountNumber, float balance, float overdrawLimit) : Account(accountNumber, balance), overdrawLimit(overdrawLimit) {}

        void displayDetails() {
            Account::displayDetails();
            cout << "Overdraw Limit: " << overdrawLimit << endl;
        }
};

int main() {
    SavingsAccount s(12345, 1000, 0.05);
    CheckingAccount c(54321, 500, 100);

    s.displayDetails();
    c.displayDetails();

    return 0;
}

