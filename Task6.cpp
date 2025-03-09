#include <iostream>
#include <cstring>
using namespace std;

struct Book
{
    int bookID;
    string title;
    string author;
    bool isAvailable;
};


int addBook(Book *books,int size) {
    Book *temp = new Book[size+1];
    for (int i = 0; i < size; i++) {
        temp[i] = books[i];
    }
    cout << "Enter Book Name : ";
    cin >> temp[size].title;
    cout << "Enter Book's Author's Name : ";
    cin >> temp[size].author;
    cout << "Enter Book ID : ";
    cin >> temp[size].bookID;
    temp[size].isAvailable = true;
    delete[] books;
    books = temp;
    cout << "Book Added" << endl;
    return 0;
}

int removeBook(Book *books, int size, int id) {
    int index = 0;
    int count = 0;
    Book *temp = new Book[size - 1];
    books = new Book[size - 1];
    if (size == 0) {
        cout << "No Books in collection" << endl;
        return size;
    }
    else {
        for (int i = 0; i < size; i++)
        {
            if (books[i].bookID == id)
            {
                index = i;
                for (int j = 0; j < size; j++)
                {
                    if (j == index)
                    {
                        continue;  
                    }
                    temp[count] = books[j];
                    count++;
                }
                delete[] books;
                books = temp;
                cout << "Book Removed" << endl;
                return size;
            }
            
            
            
        }
        cout << "Book Not Found" << endl;
        return size;
    }
}


int main() {
    Book *books = nullptr;
    int size = 0;
    int choice;

    cout << "Enter Your Choice\n1. Add Book \n2.Remove Book \n3. Search Book \n4. Display all books \n5. Exit";
    cin >> choice;
    while (choice != 5) {
        switch (choice)
        {
        case 1:
            addBook(books, size);
            size++;
            break;
        case 2:
            removeBook(books, size, 88);
            cout << "Size: " << size << endl;

        default:

            break;
        }
    }

    return 0;
}