#ifndef CUSTOMFORM_H
#define CUSTOMFORM_H

#include "Figure.h"
#include <stack>
#include <iostream>
class CustomForm : public Figure
{
    private:
    std::vector<SDL_Point> points;
    SDL_Point previousCenter = {0, 0};

    public:
    CustomForm(SDL_Color color);
    std::vector <SDL_Point> getPoints() const;
    void setPoints(std::vector <SDL_Point> newPoints);
    void addPoint(SDL_Point point);
    bool line = false;
    bool fill = false;
    virtual void draw(SDL_Renderer* render) override;
    void ScanFill(SDL_Renderer *render, SDL_Color color);
    void move(int dx, int dy);
    //virtual SDL_Point center() override;
};

#endif