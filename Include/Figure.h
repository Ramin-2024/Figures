#ifndef FIGURE_H
#define FIGURE_H

#include <SDL2/SDL.h>

class Figure
{
private:
    int x;
    int y;
    SDL_Color color;

public:
    Figure(int x, int y, SDL_Color color);
    virtual ~Figure() = default;

    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
    SDL_Color getColor() const;
    void setColor(SDL_Color newColor);
    virtual void draw(SDL_Renderer* render) = 0;
};

#endif