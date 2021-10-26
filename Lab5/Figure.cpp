#include "Figure.h"
#include <cmath>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

Figure::Figure(){}

double Figure::Space() { return 0; };
double Figure::Perimeter() { return 0; };

double Hexagon::Space() {
    return 6 * (a * a * sqrt(3)) / 4;
}

double Hexagon::Perimeter() {
    return a * 6;
}

double Triangle::Space(){
    double p; // p - perimetr/2
    p = (a+b+c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::Perimeter() {
    return a + b + c;
}

double Circle::Space() {
    return M_PI * r * r;
}

double Circle::Perimeter() {
    return 2 * M_PI * r;
}

Prism::Prism() {
    cout << "What base of Prism you want?\n";
    cout << "1. Circle\n";
    cout << "2. Triangle\n";
    cout << "3. Hexagon\n";
    int key;
    cout << "Insert key->"; cin >> key;

    if(key==1){
        cout << "\nInsert radius of base->"; double temp; cin >> temp;
        base = new Circle(temp);
    }
    else if (key == 2) {
        double a, b, c;
        cout << "\nInsert lenght of a side->"; cin >> a;
        cout << "\nInsert lenght of b side->"; cin >> b;
        cout << "\nInsert lenght of c side->"; cin >> c;
        base = new Triangle(a, b, c);
    }
    else if (key == 3) {
        double a;
        cout << "\nInsert legth of a side->"; cin >> a;
        base = new Hexagon(a);
    }

    cout << "\nInsert height of prism->"; cin >> h;

}

double Prism::Volume() {
    return (base->Space()) * h;
}

double Prism::FullSpace() {
    return (base->Perimeter() * h) + 2 * (base->Space());
}

void Prism::AboutBase() {
    cout << "Space of base is Sb=" << base->Space() << endl;
    cout << "Perimeter of base is Sp=" << base->Perimeter() << endl;
}