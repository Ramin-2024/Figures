#include <SDL2/SDL.h>
#include <iostream>
const int WIDTH = 640;
const int HEIGHT = 480;
SDL_Renderer* render = nullptr;
SDL_Window* window = nullptr;
bool sdl_init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window to error " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (render == nullptr) {
        std::cerr << "Renderer to error " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }
    return true;
}
void quit()
{
    if(render != nullptr) SDL_DestroyRenderer(render);
    if(window != nullptr) SDL_DestroyWindow(window);
    SDL_Quit();
}

 class Figure
{
    int x;
    int y;
    SDL_Color color;
    SDL_Renderer* render = nullptr;
    public:
    Figure(int x, int y, SDL_Color color) : x(x), y(y), color(color){};
    virtual ~Figure() = default;
    int getX() const {return x;}
    void setX(int newX) {x = newX;}
    int getY() const {return y;}
    void setY(int newY) {y = newY;}
    SDL_Color getColor() const {return color;}
    void setColor(SDL_Color& newColor) {color = newColor;}
    virtual void draw(SDL_Renderer* render) = 0;
    SDL_Renderer* getRender() {return render;}
    void setRender(SDL_Renderer& newRender) {render = &newRender;}
};

class Square : public Figure // квадрат
{
    private:
    int width;
    int height;
    SDL_Rect rect;
    public:
    int getWidth() const {return width;}
    void setWidth(int newWidth) {width = newWidth;}
    int getHeight() const {return height;}
    void setHeight(int newHeight) {height = newHeight;}
    SDL_Rect getRect() const {return rect;}
    void setRect(SDL_Rect& newRect) {rect = newRect;}
    Square(int sides, int x, int y, SDL_Color color) : Figure(x, y, color), width(sides), height(sides)
    {

        rect = {x, y, width, height};
        setColor(color);
    }
    void draw(SDL_Renderer* render) override
    {
        SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
        SDL_RenderFillRect(render, &rect);
    }
};

class Rectangle : public Figure
{
    SDL_Rect rect;
    int width;
    int height;
    public:
    int getWidth() const {return width;}
    void setWidth(int newWidth) {width = newWidth;}
    int getHeight() const {return height;}
    void setHeight(int newHeight) {height = newHeight;}
    Rectangle(int x, int y, int width, int height, SDL_Color color) : Figure(x, y, color)
    {
        rect.x = x;
        rect.y = y;
        rect.h = height;
        rect.w = width;
        setColor(color);
    }
    void draw(SDL_Renderer* render) override
    {
        SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);
        SDL_RenderFillRect(render, &rect);
    }

};

class Triangle {
public:
    Triangle(SDL_Renderer* renderer, SDL_Color color)
    : m_renderer(renderer), m_color(color) {}
    void setVertices(int x1, int y1, int x2, int y2, int x3, int y3) 
    {
    m_vertices[0] = {x1, y1};
    m_vertices[1] = {x2, y2};
    m_vertices[2] = {x3, y3};
    }
    void render() {
    // Set the draw color
    SDL_SetRenderDrawColor(m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);

    // Draw the triangle by connecting the vertices
    SDL_RenderDrawLine(m_renderer, m_vertices[0].x, m_vertices[0].y,m_vertices[1].x, m_vertices[1].y);
    SDL_RenderDrawLine(m_renderer, m_vertices[1].x, m_vertices[1].y,m_vertices[2].x, m_vertices[2].y);
    SDL_RenderDrawLine(m_renderer, m_vertices[2].x, m_vertices[2].y,m_vertices[0].x, m_vertices[0].y);
}
private:
    SDL_Renderer* m_renderer;
    SDL_Color m_color;
    SDL_Point m_vertices[3];
};


bool triangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3) // веришны треугольника - х1 и у1(первая вершина) и так далее
{
    if(renderer == nullptr) return false;
    SDL_Point p1 = {x1, y1}; // линия 1
    SDL_Point p2 = {x2, y2};
    SDL_Point p3 = {x3, y3};
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
    SDL_RenderDrawLine(renderer, p1.x, p1.y, p3.x, p3.y);
    SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
    return true;
}

int main(int argc, char* argv[])
{
    sdl_init("Window", WIDTH, HEIGHT);
    bool running = true;
    SDL_Event event;
    Triangle triangle(render, {0, 255, 0, 255});
    triangle.setVertices(400, 100, 300, 500, 500, 500);

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(render, 255, 255, 255, 255); // Заливаем экран чёрным
        SDL_RenderClear(render);
        SDL_Color green = {0, 255, 0, 255};
        triangle.render();
    }
    quit();
    return 0;
}
