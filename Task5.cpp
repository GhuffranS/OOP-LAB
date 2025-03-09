#include <iostream>
using namespace std;

class GroceryStore{
    public:
        string item[10];
        int price[10];

        GroceryStore(){
            for (int i = 0; i < 10; i++)
            {
                item[i] = "";
                price[i] = 0;
            }
            
        }

        void addItem(int num, string name, int val){
            item[num] = name;
            price[num] = val;
        }

        void updatePrice(int num, int val){
            price[num] = val;
            cout << "Price Updated Successfully" << endl;
        }

        void generateReceipt(int num, int quantity){
            cout << "Receipt" << endl;
            cout << "Item : " << item[num] << " Quantity : " << quantity << " Total : " << price[num] * quantity << endl;
        }

        void viewInventory(){
            for (int i = 0; i < 10; i++)
            {
                if (item[i] != "")
                {
                    cout << "Item : " << item[i] << endl;
                    cout << "Price : " << price[i]<<endl;
                }
                
            }
            
        }
};

int main(){
    GroceryStore store;
    store.addItem(0, "Sugar", 500);
    store.addItem(1, "Milk", 220);
    store.addItem(2, "Eggs", 300);
    store.generateReceipt(2, 10);
    store.viewInventory();
    return 0;
}

