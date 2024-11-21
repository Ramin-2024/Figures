#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure
{
    private:
    SDL_Rect rect;
    int width;
    int height;

    public:
    int getWidth() const;
    void setWidth(int newWidth);
    int getHeight() const;
    void setHeight(int newHeight);
    SDL_Rect getRect() const;
    void setRect(SDL_Rect& newRect);

    Rectangle(int x, int y, int width, int height, SDL_Color color);
    void draw(SDL_Renderer* render) override;
};

#endif