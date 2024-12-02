#include "RandomForm.h"

std::vector<SDL_Point> RandomForm::getPoints() const {return points;}
void RandomForm::setPoints(std::vector <SDL_Point> newPoints) {points = newPoints;}


RandomForm::RandomForm(SDL_Color color) : Figure(0, 0, color) 
{}
void RandomForm::addPoint(SDL_Point point) 
{
    if(points.size() < 6)
    points.push_back(point);
}
/*SDL_Point CustomForm::center()
{
    
    SDL_Point centroid;
    int centerX = 0;
    int centerY = 0;

    for (size_t i = 0; i < points.size(); ++i) {
        centerX += points[i].x;
        centerY += points[i].y;
    }

    centroid.x = centerX / points.size();
    centroid.y = centerY / points.size();

    // Проверка на изменение центра
    if (centroid.x != previousCenter.x || centroid.y != previousCenter.y) {
        std::cout << "Center: x = " << centroid.x << ", y = " << centroid.y << std::endl;
        previousCenter = centroid; // Обновляем предыдущий центр
    }
    return centroid;
}
*/
void RandomForm::draw(SDL_Renderer* render) 
{
    
    SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);

    if(points.size() > 1)
    {
    for(auto& point : points)
        {SDL_RenderDrawPoint(render, point.x, point.y);}
    }
    
    if(line)
    {
        for(int i = 0; i < points.size()-1; ++i)
        {
            SDL_RenderDrawLine(render, points[i].x, points[i].y, points[i+1].x, points[i+1].y);
            if(points.size()  > 1)
                SDL_RenderDrawLine(render, points[points.size()-1].x, points[points.size()-1].y, points.front().x, points.front().y);
        }
    }

    if(fill && points.size() > 1)
    {
        ScanFill(render, getColor()); 
    }
    /*if(points.size() > 1)
    { 
    center();
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderDrawPoint(render, center().x, center().y);
    }
    */
}

void RandomForm::ScanFill(SDL_Renderer* render, SDL_Color color) 
{
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);

    // Пути для хранения пересечений
    std::vector<std::pair<int, int>> intersections;

    // Определяем минимальное и максимальное y
    int minY = points.front().y;
    int maxY = points.front().y;
    for (const auto& point : points) {
        if (point.y < minY) minY = point.y;
        if (point.y > maxY) maxY = point.y;
    }

    // Проходим по всем горизонтальным линиям от minY до maxY
    for (int y = minY; y <= maxY; ++y) {
        intersections.clear();

        // Определяем пересечения для каждой линии
        for(size_t i = 0; i < points.size(); ++i) 
        {
            SDL_Point& p1 = points[i];
            SDL_Point& p2 = points[(i + 1) % points.size()];

            // Проверяем, пересекает ли линия горизонталь y
            if(((p1.y <= y && p2.y > y) || (p1.y > y && p2.y <= y)) && (p1.x != p2.x)) 
            {
                // Находим x-координат пересечения
                int interX = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
                intersections.emplace_back(interX, y);
            }
        }

        // Если есть пересечения, заполняем между ними
        if (!intersections.empty()) {
            // Сортируем пересечения
            std::sort(intersections.begin(), intersections.end());

            // Заполняем пиксели между каждой парой пересечений
            for(size_t i = 0; i < intersections.size() - 1; i += 2) 
            {
                // Заполняем пиксели между intersections[i].first и intersections[i + 1].first
                SDL_RenderDrawLine(render, intersections[i].first, y, intersections[i + 1].first, y);
            }
        }
    }
}