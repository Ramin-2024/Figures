#ifndef CUSTOMFORM_H
#define CUSTOMFORM_H

#include "Figure.h"
#include <iostream>
class CustomForm : public Figure
{
    private:
    std::vector<SDL_Point> points;

    public:
    CustomForm(SDL_Color color);
    std::vector <SDL_Point> getPoints() const;
    void setPoints(std::vector <SDL_Point> newPoints);
    void addPoint(SDL_Point point);
    bool line = false;
    bool fill = false;
    void draw(SDL_Renderer* render) override;
    
};

#endif