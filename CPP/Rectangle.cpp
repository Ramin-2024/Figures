#include "Rectangle.h"

int Rectangle::getWidth() const { return width; }

void Rectangle::setWidth(int newWidth) { 
    if (newWidth >= 0) {
        width = newWidth; 
        rect.w = newWidth; // Обновить ширину rect
    }
}

int Rectangle::getHeight() const { return height; }

void Rectangle::setHeight(int newHeight) { 
    if (newHeight >= 0) {
        height = newHeight; 
        rect.h = newHeight; // Обновить высоту rect
    }
}

SDL_Rect Rectangle::getRect() const { return rect; }

void Rectangle::setRect(SDL_Rect& newRect) { 
    rect = newRect; 
    width = newRect.w;  // Обновить хранение ширины
    height = newRect.h; // Обновить хранение высоты
}

Rectangle::Rectangle(int x, int y, int width, int height, SDL_Color color) 
    : Figure(x, y, color),  
      width(width), 
      height(height), 
      rect({x, y, width, height}) // Инициализация rect
{}

void Rectangle::draw(SDL_Renderer* render) 
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    SDL_RenderFillRect(render, &rect); // Используем член класса rect
}
