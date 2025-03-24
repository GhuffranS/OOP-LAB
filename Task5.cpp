#include <iostream>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub) : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() { cout << "Title: " << title << " | Published: " << publicationDate << " | ID: " << uniqueID << " | Publisher: " << publisher << endl; }
    virtual void checkOut() { cout << title << " has been checked out." << endl; }
    virtual void returnItem() { cout << title << " has been returned." << endl; }
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages) : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override { cout << "Book: " << title << " | Author: " << author << " | ISBN: " << ISBN << " | Pages: " << numberOfPages << endl; }
};

class DVD : public Media {
private:
    string director, rating;
    int duration;
public:
    DVD(string t, string pDate, string id, string pub, string d, int dur, string r) : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override { cout << "DVD: " << title << " | Director: " << director << " | Duration: " << duration << " min | Rating: " << rating << endl; }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string id, string pub, string a, string g, int tracks) : Media(t, pDate, id, pub), artist(a), genre(g), numberOfTracks(tracks) {}
    void displayInfo() override { cout << "CD: " << title << " | Artist: " << artist << " | Genre: " << genre << " | Tracks: " << numberOfTracks << endl; }
};

class Magazine : public Media {
public:
    Magazine(string t, string pDate, string id, string pub) : Media(t, pDate, id, pub) {}
    void displayInfo() override { cout << "Magazine: " << title << " | Published: " << publicationDate << " | Publisher: " << publisher << endl; }
};

int main() {
    Book b("C++ Programming", "2023", "B101", "TechBooks", "John Doe", "123456789", 450);
    DVD d("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", "Pop", 9);
    Magazine m("National Geographic", "2024", "M404", "NatGeo");
    
    b.displayInfo();
    d.displayInfo();
    c.displayInfo();
    m.displayInfo();
    
    b.checkOut();
    b.returnItem();
    
    return 0;
}