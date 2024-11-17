#include "Figure.h"

Figure::Figure(int x, int y, SDL_Color color) : x(x), y(y), color(color) {}

int Figure::getX() const {
    return x;
}

void Figure::setX(int newX) {
    x = newX;
}

int Figure::getY() const {
    return y;
}

void Figure::setY(int newY) {
    y = newY;
}

SDL_Color Figure::getColor() const {
    return color;
}

void Figure::setColor(SDL_Color newColor) {
    color = newColor;
}

