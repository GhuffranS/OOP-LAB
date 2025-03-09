#include <iostream>
#include<string>
using namespace std;

struct Product
{
    int productID;
    string name;
    int quantity;
    float price;
};

void addProduct(Product *&arr, int &size) {
    Product *temp = new Product[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    cout << "Enter Product ID: ";
    cin >> temp[size].productID;
    cin.ignore(); 
    cout << "Enter Product Name: ";
    getline(cin, temp[size].name);
    cout << "Enter Product Price: ";
    cin >> temp[size].price;
    cout << "Enter Product Quantity: ";
    cin >> temp[size].quantity;

    delete[] arr;
    arr = temp;
    size++;
    cout << "Product Added" << endl;

}

int updateProduct(Product *arr, int size, int id) {
    if (size == 0)
    {
        cout << "No Products to update" << endl;
        return 0;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i].productID == id)
        {
            cout << "Enter New Name : ";
            cin >> arr[i].name;
            cout << "Enter New Price : ";
            cin >> arr[i].price;
            cout << "Enter New Quantity : ";
            cin >> arr[i].quantity;
            cout << "Product Updated Successfully" << endl;
            return 0;
        }
        
    }
    cout << "Product Not Found" << endl;
    return 0;
}

void removeProduct(Product*& arr, int& size, int id) {
    if (size == 0) {
        cout << "No Products to remove" << endl;
        return;
    }

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i].productID == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        Product* temp = new Product[size - 1];
        for (int i = 0; i < size - 1; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size--;
        cout << "Product Removed Successfully" << endl;
    } else {
        cout << "Product Not Found" << endl;
    }
}

void totalValue(Product* arr, int size) {
    float total = 0.0; 
    for (int i = 0; i < size; i++) {
        total += arr[i].price * arr[i].quantity; 
    }
    cout << "Total: " << total << endl;
}




int main() {
    int choice;
    int size = 0;
    Product *products = nullptr;
    cout << "\nProduct Management" << endl;
    while (choice != 4)
    {
        cout << "Enter Your Choice\n1. Add Product \n2. Remove Product \n3. Update Product\n4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addProduct(products, size);
            break;
        case 2:
            int removeid;
            cout << "Enter ID Of Product to remove : ";
            cin >> removeid;
            removeProduct(products, size, removeid);
            break;
        case 3:
            int updateid;
            cout << "Enter ID Of Product to Update : ";
            cin >> updateid;
            updateProduct(products, size, updateid);
            break;
        case 4:
            totalValue(products, size);
            break;
        default:
            break;
        }
    }
    return 0;
}
