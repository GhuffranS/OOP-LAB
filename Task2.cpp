#include <iostream>
#include <cmath>
#define PI 3.142
using namespace std;

class Shape {
protected:
    int x, y;
    string color;
    double borderThickness;

public:
    Shape(int px, int py, string c, double bt = 1.0) : x(px), y(py), color(c), borderThickness(bt) {}
    virtual void draw() { cout << "Drawing Shape at (" << x << ", " << y << ") with color " << color << endl; }
    virtual double calculateArea() { return 0; }
    virtual double calculatePerimeter() { return 0; }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(int px, int py, string c, double r) : Shape(px, py, c), radius(r) {}
    void draw() override { cout << "Drawing Circle at (" << x << ", " << y << ") with radius " << radius << endl; }
    double calculateArea() override { return PI * radius * radius; }
    double calculatePerimeter() override { return 2 * PI * radius; }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(int px, int py, string c, double w, double h) : Shape(px, py, c), width(w), height(h) {}
    void draw() override { cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << endl; }
    double calculateArea() override { return width * height; }
    double calculatePerimeter() override { return 2 * (width + height); }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(int px, int py, string c, double b, double h) : Shape(px, py, c), base(b), height(h) {}
    void draw() override { cout << "Drawing Triangle at (" << x << ", " << y << ") with base " << base << " and height " << height << endl; }
    double calculateArea() override { return 0.5 * base * height; }
    double calculatePerimeter() override { return base + 2 * sqrt((base / 2) * (base / 2) + height * height); }
};

int main() {
    Circle c(10, 10, "Red", 5);
    c.draw();
    cout << "Area: " << c.calculateArea() << " | Perimeter: " << c.calculatePerimeter() << endl;

    Rectangle r(20, 20, "Blue", 10, 5);
    r.draw();
    cout << "Area: " << r.calculateArea() << " | Perimeter: " << r.calculatePerimeter() << endl;

    Triangle t(30, 30, "Green", 8, 6);
    t.draw();
    cout << "Area: " << t.calculateArea() << " | Perimeter: " << t.calculatePerimeter() << endl;

    return 0;
}