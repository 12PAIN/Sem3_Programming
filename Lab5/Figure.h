#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    Figure();
    virtual double Space();
    virtual double Perimeter();
};

class Circle : public Figure{

private:

    double r;

public:

    Circle(double new_r){
        r=new_r;
    };

    virtual double Space();
    virtual double Perimeter();

};

class Triangle : public Figure{

private:

    double a,b,c;

public:
    Triangle(double a_new, double b_new, double c_new){

        a=a_new;
        b=b_new;
        c=c_new;

    };

    virtual double Space();
    virtual double Perimeter();

};

class Hexagon : public Figure {
private:

    double a;

public:
    Hexagon(double new_a) {
        a = new_a;
    }
    virtual double Space();
    virtual double Perimeter();
};

class Prism {

private:
    Figure* base;
    double h;
public:
    Prism();

    ~Prism() {
        delete base;
    }

    virtual double FullSpace();
    virtual double Volume();
    virtual void AboutBase();
};

#endif // FIGURE_H
