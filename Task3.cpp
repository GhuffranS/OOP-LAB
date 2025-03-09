#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Professor{
    private:
        string name;
        string department;
    public:
        Professor(string nameI, string departmentI){
            name = nameI;
            department = departmentI;
        }



        string getName(){
            return name;
        }

        string getDepartment(){
            return department;
        }

        void displayDetails(){
            cout << "Name : " << name << endl;
            cout << "Department : " << department << endl;
        }
};

class University{
    private:
        string name;
        Professor **professors;
        int numProfessors;
        int capacity;
    public:
        University(string nameI, int initialCapacity = 5) : name(nameI), numProfessors(0),capacity(initialCapacity){
            professors = new Professor *[capacity];
        }

        void addProfessor(Professor* professor){
            if (numProfessors == capacity){
                capacity *= 2;
                Professor **newProfessors = new Professor *[capacity];
                for (int i = 0; i < numProfessors; i++)
                {
                    newProfessors[i] = professors[i];
                }
                delete[] professors;
                professors = newProfessors;
                
            }
            professors[numProfessors++] = professor;
        }

        void display() {
            for (int i = 0; i < numProfessors; i++)
            {
                professors[i]->displayDetails();
            }
            
        }

        ~University(){
            for (int i = 0; i < numProfessors; i++)
            {
                delete professors[i];
            }

            delete[] professors;
            
        }
};

int main(){
    University fastUni("FAST NUCES");

    Professor *professor1 = new Professor("Shahzad", "ISL");
    Professor *professor2 = new Professor("Jawed", "SE");
    fastUni.addProfessor(professor1);
    fastUni.addProfessor(professor2);
    fastUni.display();
    fastUni.~University();
}