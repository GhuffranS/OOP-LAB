#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    string title;
    string director;
    int duration; 

public:
    Movie(string t, string d, int dur) : title(t), director(d), duration(dur) {}

    void display() {
        cout << "Title: " << title << ", Director: " << director << ", Duration: " << duration << " minutes" << endl;
    }
};

class CinemaHall {
private:
    string hallName;
    Movie* movies[10]; 
    int movieCount;

public:
    CinemaHall(string name) : hallName(name), movieCount(0) {}

    void addMovie(Movie* movie) {
        if (movieCount < 10) {
            movies[movieCount++] = movie;
        }
    }

    void displayDetails() {
        cout << "Cinema Hall: " << hallName << endl;
        cout << "Movies currently being screened:" << endl;
        for (int i = 0; i < movieCount; i++) {
            movies[i]->display();
        }
    }
};

int main() {
    CinemaHall hall("Grand Cinema");
    Movie movie1("Inception", "Christopher Nolan", 148);
    Movie movie2("The Matrix", "Lana Wachowski, Lilly Wachowski", 136);

    hall.addMovie(&movie1);
    hall.addMovie(&movie2);

    hall.displayDetails();

    return 0;
}
