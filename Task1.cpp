#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, double bal, string name, string type)
        : accountNumber(accNo), balance(bal), accountHolderName(name), accountType(type) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation is account-type specific." << endl;
    }

    virtual void printStatement() {
        cout << "Account Statement for " << accountHolderName << " (" << accountType << ")" << endl;
        cout << "Account Number: " << accountNumber << " | Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, double bal, string name, double rate, double minBal)
        : Account(accNo, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest added: " << interest << " | New Balance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, double bal, string name)
        : Account(accNo, bal, name, "Checking") {}

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Checking Account Withdrawal: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal failed: Insufficient funds or invalid amount." << endl;
        }
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityPeriod; 

public:
    FixedDepositAccount(int accNo, double bal, string name, double rate, int maturity)
        : Account(accNo, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityPeriod(maturity) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest: " << interest << " (not added until maturity)" << endl;
    }
};

int main() {
    SavingsAccount sa(101, 5000, "Alice", 3.5, 1000);
    sa.printStatement();
    sa.deposit(1000);
    sa.calculateInterest();
    sa.withdraw(2000);

    CheckingAccount ca(102, 3000, "Bob");
    ca.printStatement();
    ca.withdraw(500);

    FixedDepositAccount fda(103, 10000, "Charlie", 5.0, 12);
    fda.printStatement();
    fda.calculateInterest();

    return 0;
}