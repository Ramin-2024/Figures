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

bool triangle(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int x3, int y3) // координаты линий. х1 и у1 = координаты первой линии, х2 и у2 и х3 и у3 - координаты второй и третей линий.
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

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(render, 255, 255, 255, 255); // Заливаем экран чёрным
        SDL_RenderClear(render);
        SDL_Color green = {0, 255, 0, 255};
        Square top(150, 300, 220, green);
        top.draw(render);
        Rectangle recta(200, 100, 50, 80, green);
        recta.draw(render);
        
        SDL_RenderPresent(render); 
    }
    quit();
    return 0;
}
