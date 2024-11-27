#ifndef CUB_H
#define CUB_H

#include "Figure.h"

class Cub : public Figure
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
    Cub(int sides, int x, int y, SDL_Color color);
    void draw(SDL_Renderer* render) override;
    virtual SDL_Point center() override;
};


#endif