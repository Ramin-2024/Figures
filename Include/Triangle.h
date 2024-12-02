#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure
{
    private:
    float x1, x2, x3, y1, y2, y3;
    SDL_Renderer* render;
    public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Renderer* render, SDL_Color color);
    virtual ~Triangle() override = default;
    virtual void draw(SDL_Renderer* render) override;
    //virtual SDL_Point center() override;
};

#endif