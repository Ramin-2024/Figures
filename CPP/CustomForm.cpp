#include "CustomForm.h"

std::array<SDL_Point, 6> CustomForm::getPoints() const {return points;}
void CustomForm::setPoints(std::array <SDL_Point, 6> newPoints) {points = newPoints;}
CustomForm::CustomForm(SDL_Color color) : Figure(0, 0, color)
{}
void CustomForm::draw(SDL_Renderer* render) 
{
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
    for(auto& point : points)
    {
        SDL_RenderDrawPoint(render, point.x, point.y);
        
    }
}




