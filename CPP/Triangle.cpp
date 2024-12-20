#include "Triangle.h"



Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Renderer* render, SDL_Color color) : Figure(0, 0, color), x1(x1),
    y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), render(render)
    {
        //center();
    }

/*SDL_Point Triangle::center()
{
    SDL_Point centroid;
    centroid.x = (x1 + x2 + x3) / 3;
    centroid.y = (y1 + y2 + y3) / 3; 
    return centroid;
}
*/
void Triangle::draw(SDL_Renderer* render)
{
        if(render != nullptr)
        {
            SDL_Vertex vertices[3];
            vertices[0].position = {x1, y1};
            vertices[0].color = this->getColor();
                
            vertices[1].position = {x2, y2};
            vertices[1].color = this->getColor();
                
            vertices[2].position = {x3, y3};
            vertices[2].color = this->getColor();
                
            SDL_RenderGeometry(render, nullptr, vertices, 3, nullptr, 0);
            SDL_RenderPresent(render);
            //SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
            //SDL_RenderDrawPoint(render, center().x, center().y);  
        }
}
    