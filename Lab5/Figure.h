#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
    virtual double Space() = 0;
    virtual double Perimeter() = 0;
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

    Prism(double new_h, Figure* new_base) {
        h = new_h;
        base = BaseAlloc(new_base);
    }

    ~Prism() {
        delete base;
    }

    virtual Figure* BaseAlloc(Figure*) = 0;
    virtual double FullSpace();
    virtual double Volume();
    virtual void AboutBase();
};

class TrianglePrism : protected Prism {

    TrianglePrism(double new_h, Figure* new_base) : Prism(new_h, new_base) {};
    virtual Figure* BaseAlloc(Figure*);
};


#endif // FIGURE_H
