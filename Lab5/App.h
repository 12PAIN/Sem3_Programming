#ifndef APP_H
#define APP_H
#include "Figure.h"

class App
{

private:

public:
    App() {
    
        Start();
    
    };

    void Start();
    void Menu(int&);
    void Action(int&);
    double ReturnSpace(Figure*);
    Figure* createNewFigure(int&);

};

#endif // APP_H
