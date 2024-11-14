#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure
{
    private:
    int width;
    int height;
    SDL_Rect rect;

    public:
    int getWidth() const;
    void setWidth(int newWidth);
    int getHeight() const;
    void setHeight(int newHeight);
    SDL_Rect getRect() const;
    void setRect(SDL_Rect& newRect);
    Square(int sides, int x, int y, SDL_Color color);
    void draw(SDL_Renderer* render) override;
};

#endif