#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

const double pi{3.14};

using namespace std;

class Figure {
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Rect: public Figure {
    double width;
    double height;
public:
    Rect(double w, double h) : width(w), height(h) {}
    double Area()override {
        return width * height;
    }
    double Perimeter()override {
        return (width + height) * 2;
    } 
    string Name() override {
        return "RECT";
    }
};
class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) :a(a), b(b), c(c) {}
    double Perimeter()override {
        return a + b + c;
    }
    double Area()override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    string Name()override {
        return "TRIANGLE";
    }
private:
    double a;
    double b;
    double c;
};
class Circle : public Figure {
public:
    Circle(double rad) : r(rad) {}
    double Perimeter() override{
        return 2 * pi * r;
    }
    double Area() override {
        return pi * r * r;
    }
    string Name()override {
        return "CIRCLE";
    }
private:
    double r;
};

shared_ptr<Figure> CreateFigure(istream& is) {
    shared_ptr<Figure> ptr;

    string name;
    is >> name;
    if (name == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        ptr = make_shared<Triangle>(a, b, c);
    }
    if (name == "CIRCLE") {
        double r;
        is >> r;
        ptr = make_shared<Circle>(r);
    }
    if (name == "RECT") {
        double w, h;
        is >> w >> h;
        ptr = make_shared<Rect>(w, h);
    }
    return ptr;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}