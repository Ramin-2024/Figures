#ifndef CUSTOMFORM_H
#define CUSTOMFORM_H

#include "Figure.h"
#include <iostream>
class CustomForm : public Figure
{
    private:
    std::array <SDL_Point, 6> points;
    

    public:
    CustomForm(SDL_Color color);
    std::array <SDL_Point, 6> getPoints() const;
    void setPoints(std::array <SDL_Point, 6> newPoints);
    void fill();
    void draw(SDL_Renderer* render) override;
    
};

#endif