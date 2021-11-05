#include "Figure.h"
#include <cmath>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

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

void Triangle::GetParams(double& new_a, double& new_b, double& new_c) {
    new_a = a;
    new_b = b;
    new_c = c;
}

double Circle::Space() {
    return M_PI * r * r;
}

double Circle::Perimeter() {
    return 2 * M_PI * r;
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

Figure* TrianglePrism::BaseAlloc(Figure* new_figure) {

    return (Prism*)new Triangle(a,b,c);
}