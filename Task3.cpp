#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person {
private:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Person {
private:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications)
        : Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() {
        Teacher::displayDetails();
        Researcher::displayDetails();
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    Professor p("Dr. John Doe", 45, "Computer Science", "Machine Learning", 10);
    p.displayDetails();
    return 0;
}