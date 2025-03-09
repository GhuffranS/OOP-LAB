#include <iostream>
#include <string>

using namespace std;

class TourGuide {
private:
    string name;
    int yearsExperience;
    string specialization;

public:
    TourGuide(string name, int yearsExperience, string specialization) : 
        name(name), yearsExperience(yearsExperience), specialization(specialization) {}

    void displayDetails() const {
        cout << "Tour Guide Name: " << name << endl;
        cout << "Years of Experience: " << yearsExperience << endl;
        cout << "Specialization: " << specialization << endl;
    }
};

class TravelAgency {
private:
    string agencyName;
    TourGuide** tourGuides;
    int guideCount;
    int capacity;

public:
    TravelAgency(string agencyName, int initialCapacity = 5) : 
        agencyName(agencyName), guideCount(0), capacity(initialCapacity) {
        tourGuides = new TourGuide*[capacity];
    }

    void addTourGuide(TourGuide* guide) {
        if (guideCount == capacity) {
            capacity *= 2;
            TourGuide** newGuides = new TourGuide*[capacity];
            for (int i = 0; i < guideCount; i++) {
                newGuides[i] = tourGuides[i];
            }
            delete[] tourGuides;
            tourGuides = newGuides;
        }
        tourGuides[guideCount++] = guide;
    }

    void displayAgencyDetails() const {
        cout << "Travel Agency Name: " << agencyName << endl;
        cout << "Tour Guides:" << endl;
        if (guideCount == 0) {
            cout << "No tour guides currently associated." << endl;
            return;
        }

        for (int i = 0; i < guideCount; i++) {
            tourGuides[i]->displayDetails();
            cout << "--------------------" << endl;
        }
    }

    ~TravelAgency() {
        delete[] tourGuides;
    }
};

int main() {
    TourGuide* guide1 = new TourGuide("Alice Johnson", 5, "Historical Tours");
    TourGuide* guide2 = new TourGuide("Bob Williams", 8, "Nature and Wildlife");
    TourGuide* guide3 = new TourGuide("Charlie Brown", 3, "City Sightseeing");

    TravelAgency agency1("Adventure Tours");
    agency1.addTourGuide(guide1);
    agency1.addTourGuide(guide2);

    TravelAgency agency2("City Explorer");
    agency2.addTourGuide(guide3);

    agency1.displayAgencyDetails();
    agency2.displayAgencyDetails();

    delete guide1;
    delete guide2;
    delete guide3;

    return 0;
}