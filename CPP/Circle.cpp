#include "Circle.h"

Circle::Circle(int x, int y, SDL_Color color, int radius) : Figure(x, y, color), radius(radius), diameter(radius * 2) {}
SDL_Point Circle::center()
{
    SDL_Point centroid;
    centroid.x = getX();
    centroid.y = getY();
    return centroid;
}

void Circle::draw(SDL_Renderer* render) 
{
        if (render == nullptr) return;

        SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);

        int x_pos = radius;
        int y_pos = 0;
        int err = 0;

        while (x_pos >= y_pos) 
        {
            // Заполняем горизонтальные линии от левой до правой стороны круга
            SDL_RenderDrawLine(render, this->getX() - x_pos, this->getY() + y_pos, this->getX() + x_pos, this->getY() + y_pos);
            SDL_RenderDrawLine(render, this->getX() - x_pos, this->getY() - y_pos, this->getX() + x_pos, this->getY() - y_pos);
            SDL_RenderDrawLine(render, this->getX() - y_pos, this->getY() + x_pos, this->getX() + y_pos, this->getY() + x_pos);
            SDL_RenderDrawLine(render, this->getX() - y_pos, this->getY() - x_pos, this->getX() + y_pos, this->getY() - x_pos);

            if (err <= x_pos) 
            {
                y_pos++;
                err += (y_pos * 2 + 1);
            }

            if (err > y_pos) 
            {
                x_pos--;
                err -= (x_pos * 2 + 1);
            }
        }
}