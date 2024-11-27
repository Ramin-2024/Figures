#include "Cub.h"
int Cub::getWidth() const {return width;}
void Cub::setWidth(int newWidth) {width = newWidth;}
int Cub::getHeight() const {return height;}
void Cub::setHeight(int newHeight) {height = newHeight;}
SDL_Rect Cub::getRect() const {return rect;}
void Cub::setRect(SDL_Rect& newRect) {rect = newRect;}

Cub::Cub(int sides, int x, int y, SDL_Color color) : Figure(x, y, color), width(sides), height(sides), rect({x, y, width, height}) 
{
    //center();
}

SDL_Point Cub::center()
{
    SDL_Point centroid;
    centroid.x = (getX() + (getX() + width)) / 2;
    centroid.y = (getY() + (getY() + height)) / 2;
    std::cout << "x = " << centroid.x << "y = " << centroid.y;
    return centroid;
}

void Cub::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    SDL_RenderFillRect(render, &rect);
}