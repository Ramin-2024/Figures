#include "Square.h"

int Square::getWidth() const {return width;}
void Square::setWidth(int newWidth) {width = newWidth;}
int Square::getHeight() const {return height;}
void Square::setHeight(int newHeight) {height = newHeight;}
SDL_Rect Square::getRect() const {return rect;}
void Square::setRect(SDL_Rect& newRect) {rect = newRect;}
Square::Square(int sides, int x, int y, SDL_Color color) : Figure(x, y, color), width(sides), height(sides), rect({x, y, width, height}) {}
void Square::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    SDL_RenderFillRect(render, &rect);
}