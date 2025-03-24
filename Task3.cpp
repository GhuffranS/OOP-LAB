#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() { return amount * exchangeRate; }
    virtual double convertTo(Currency &target) { return convertToBase() / target.exchangeRate; }
    virtual void displayCurrency() { cout << currencySymbol << amount << " (" << currencyCode << ")" << endl; }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    void displayCurrency() override { cout << "$" << amount << " (USD)" << endl; }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
    void displayCurrency() override { cout << "€" << amount << " (EUR)" << endl; }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}
    void displayCurrency() override { cout << "₹" << amount << " (INR)" << endl; }
};

int main() {
    Dollar d(100);
    Euro e(50);
    Rupee r(5000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << "100 USD to EUR: " << d.convertTo(e) << endl;
    cout << "50 EUR to INR: " << e.convertTo(r) << endl;
    cout << "5000 INR to USD: " << r.convertTo(d) << endl;

    return 0;
}
