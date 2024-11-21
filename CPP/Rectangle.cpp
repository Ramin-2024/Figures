#include "Rectangle.h"

int Rectangle::getWidth() const {return width;}
void Rectangle::setWidth(int newWidth) {width = newWidth;}
int Rectangle::getHeight() const {return height;}
void Rectangle::setHeight(int newHeight) {height = newHeight;}
SDL_Rect Rectangle::getRect() const {return rect;}
void Rectangle::setRect(SDL_Rect& newRect) {rect = newRect;}

Rectangle::Rectangle(int x, int y, int width, int height, SDL_Color color) : Figure(x, y, color), rect({x, y, width, height}){}
void Rectangle::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    SDL_RenderFillRect(render, &rect);
}
