#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure 
{
private:
    int radius;
    int diameter;

public:
    Circle(int x, int y, SDL_Color color, int radius);
    void draw(SDL_Renderer* render) override;
    //virtual SDL_Point center() override;
    
};


#endif