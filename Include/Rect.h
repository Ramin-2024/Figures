#ifndef RECT_H
#define RECT_H

#include "Figure.h"

class Rect : public Figure
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


    Rect(int x, int y, int width, int height, SDL_Color color);
    void move(int dx, int dy);
    void draw(SDL_Renderer* render) override;
    //virtual SDL_Point center() override;
    
};

#endif