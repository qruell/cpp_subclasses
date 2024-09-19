#include <iostream>
#include <string>

enum class Color {
    Red,
    Green,
    Blue,
    Yellow
};

class Shape {
protected:
    Color color;

public:
    Shape(Color c) : color(c) {}

    virtual void display() const = 0;

    std::string colorToString() const {
        switch (color) {
        case Color::Red:    return "Red";
        case Color::Green:  return "Green";
        case Color::Blue:   return "Blue";
        case Color::Yellow: return "Yellow";
        default:            return "Unknown";
        }
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, Color c) : Shape(c), radius(r) {}

    void display() const override {
        std::cout << "Circle of radius " << radius
            << " and color " << colorToString() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h, Color c)
        : Shape(c), width(w), height(h) {}

    void display() const override {
        std::cout << "Rectangle of width " << width
            << ", height " << height
            << " and color " << colorToString() << std::endl;
    }
};

int main() {
    Circle circle(5.0, Color::Red);
    Rectangle rectangle(4.0, 6.0, Color::Blue);

    circle.display();
    rectangle.display();

    return 0;
}
