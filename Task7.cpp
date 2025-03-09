#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

void sortProducts(Product products[], int count) {
    sort(products, products + count, [](Product a, Product b) {
        return a.price < b.price;
    });
}

void searchProduct(Product products[], int count, const string& searchName) {
    for (int i = 0; i < count; i++) {
        if (products[i].name == searchName) {
            cout << "Product found: ID: " << products[i].id 
                 << ", Name: " << products[i].name 
                 << ", Price: " << products[i].price << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

int main() {
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    while (productCount < MAX_PRODUCTS) {
        cout << "Enter product ID (or -1 to stop): ";
        cin >> products[productCount].id;
        if (products[productCount].id == -1) break;

        cout << "Enter product name: ";
        cin >> products[productCount].name;

        cout << "Enter product price: ";
        cin >> products[productCount].price;

        productCount++;
    }

    sortProducts(products, productCount);

    cout << "Sorted products by price:" << endl;
    for (int i = 0; i < productCount; i++) {
        cout << "ID: " << products[i].id 
             << ", Name: " << products[i].name 
             << ", Price: " << products[i].price << endl;
    }

    string searchName;
    cout << "Enter product name to search: ";
    cin >> searchName;
    searchProduct(products, productCount, searchName);

    return 0;
}
