#include "Rect.h"

int Rect::getWidth() const { return width; }

void Rect::setWidth(int newWidth) { 
    if (newWidth >= 0) {
        width = newWidth; 
        rect.w = newWidth; // Обновить ширину rect
    }
}

int Rect::getHeight() const { return height; }

void Rect::setHeight(int newHeight) { 
    if (newHeight >= 0) {
        height = newHeight; 
        rect.h = newHeight; // Обновить высоту rect
    }
}

SDL_Rect Rect::getRect() const { return rect; }

void Rect::setRect(SDL_Rect& newRect) { 
    rect = newRect; 
    width = newRect.w;  // Обновить хранение ширины
    height = newRect.h; // Обновить хранение высоты
}

Rect::Rect(int x, int y, int width, int height, SDL_Color color) 
    : Figure(x, y, color),  
      width(width), 
      height(height), 
      rect({x, y, width, height}) {}
SDL_Point Rect::center()
{
    SDL_Point centroid;
    centroid.x = (getX() + (getX() + width)) / 2;
    centroid.y = (getY() + (getY() + height)) / 2;
    std::cout << "x = " << centroid.x << "y = " << centroid.y;
    return centroid;
}
void Rect::draw(SDL_Renderer* render) 
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    SDL_RenderFillRect(render, &rect); // Используем член класса rect
}
