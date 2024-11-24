#include "CustomForm.h"

std::vector<SDL_Point> CustomForm::getPoints() const {return points;}
void CustomForm::setPoints(std::vector <SDL_Point> newPoints) {points = newPoints;}
CustomForm::CustomForm(SDL_Color color) : Figure(0, 0, color) {}
void CustomForm::addPoint(SDL_Point point) 
{
    if(points.size() < 6)
    points.push_back(point);
}
void CustomForm::draw(SDL_Renderer* render) 
{
    SDL_Vertex verticec[points.size()];
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);

    if(points.size() > 1)
    {
    //if(points.size() < 6)
    //{
    for(auto& point : points)
        {SDL_RenderDrawPoint(render, point.x, point.y);}
    }
    //}
    
    if(line)
    {
        for(float i = 0; i < points.size()-1; ++i)
        {
            SDL_RenderDrawLine(render, points[i].x, points[i].y, points[i+1].x, points[i+1].y);
            if(points.size()  > 1)
                SDL_RenderDrawLine(render, points[points.size()-1].x, points[points.size()-1].y, points.front().x, points.front().y);
        }
    }
    if (fill && points.size() > 2) 
    {
    // Добавим первую точку в конец вектора для замыкания полигона
    std::vector<SDL_Vertex> vertices(points.size() + 1);
    for (size_t i = 0; i < points.size(); ++i) {
        vertices[i].position = {static_cast<float>(points[i].x), static_cast<float>(points[i].y)};
        vertices[i].color = getColor();
    }
    vertices[points.size()] = vertices[0]; // Замыкание полигона

    // Теперь рисуем заполненный полигон
    SDL_RenderGeometry(render, nullptr, vertices.data(), vertices.size(), nullptr, 0);
    }

}





