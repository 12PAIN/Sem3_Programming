#include "App.h"
#include <iostream>

using namespace std;

void App::Start(){
    int key = -1;

    do{
        Menu(key);
        Action(key);
    }while(key != 0);

}

void App::Menu(int& key){
    cout << endl;
    cout << "-----MENU-----" << endl;
    cout << "1) Create figure" << endl;
    cout << "2) Create prism(or cylinder)" << endl;
    cout << "Insert key->"; cin >> key;
    cout << endl;
}

void App::Action(int& key){

    if(key == 1){

        cout << "What figure you want?" << endl;
        cout << "1) Triangle" << endl;
        cout << "2) Circle" << endl;
        cout << "3) Hexagon" << endl;
        cout << "Insert key->"; int temp; cin >> temp;
        cout << endl;

        if(temp == 1){
            Figure* figure;
            double a,b,c;
            cout << "Insert side a="; cin >> a;
            cout << "Insert side b="; cin >> b;
            cout << "Insert side c="; cin >> c;
            figure = new Triangle(a,b,c);
            cout << endl;
            cout << "Perimeter of figure P=" << figure->Perimeter() << endl;
            cout << "Space of figure S=" << figure->Space() << endl;
            delete figure;

        }else if(temp == 2){
            Figure* figure;
            double r;
            cout << "Insert radius="; cin >> r;
            figure = new Circle(r);
            cout << endl;
            cout << "Perimeter of figure P=" << figure->Perimeter() << endl;
            cout << "Space of figure S=" << figure->Space() << endl;

            delete figure;

        }
        else if (temp == 3) {
            Figure* figure;
            double a;
            cout << "Insert lenght of a side a="; cin >> a;
            figure = new Hexagon(a);
            cout << endl;
            cout << "Perimeter of figure P=" << figure->Perimeter() << endl;
            cout << "Space of figure S=" << figure->Space() << endl;
            delete figure;
        }
        
    }
    else if (key == 2) {
        Figure* new_t = new Triangle(1,1,1);
        Prism* new_prism = (Prism*)new TrianglePrism(1.2, new_t);
        cout << endl;
        new_prism->AboutBase();
        cout << "Space of surface is SF=" << new_prism->FullSpace() << endl;
        cout << "Volume of prism(cylinder) is V=" <<new_prism->Volume() << endl;
        cout << endl;
    }

}
