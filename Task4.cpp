#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() { cout << "Name: " << name << " | ID: " << id << " | Email: " << email << endl; }
    string getName() { return name; }
};

class Student : public Person {
private:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, string c, double g, int y) : Person(n, i, a, p, e), coursesEnrolled(c), GPA(g), enrollmentYear(y) {}
    void displayInfo() override { cout << "Student: " << name << " | GPA: " << GPA << " | Courses: " << coursesEnrolled << endl; }
};

class Professor : public Person {
private:
    string department, coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, string c, double s) : Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s) {}
    void displayInfo() override { cout << "Professor: " << name << " | Dept: " << department << " | Courses: " << coursesTaught << " | Salary: " << salary << endl; }
};

class Staff : public Person {
private:
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s) : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}
    void displayInfo() override { cout << "Staff: " << name << " | Dept: " << department << " | Position: " << position << " | Salary: " << salary << endl; }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string id, string name, int c, string instr, string sched) : courseId(id), courseName(name), credits(c), instructor(instr), schedule(sched) {}
    void registerStudent(Student &s) { cout << "Student " << s.getName() << " registered for " << courseName << endl; }
};

int main() {
    Student s("Alice", "S123", "123 Street", "1234567890", "alice@email.com", "Math, CS", 3.8, 2022);
    Professor p("Dr. Smith", "P456", "456 Avenue", "9876543210", "smith@email.com", "CS", "Algorithms", 90000);
    Staff st("Bob", "ST789", "789 Road", "5551234567", "bob@email.com", "Admin", "Manager", 60000);
    Course c("C101", "Mathematics", 3, "Dr. Smith", "MWF 10AM");
    
    s.displayInfo();
    p.displayInfo();
    st.displayInfo();
    c.registerStudent(s);
    
    return 0;
}