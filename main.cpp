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
    private:
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

class Triangle : public Figure {
    private:
    float x1, x2, x3, y1, y2, y3;
    SDL_Renderer* render;
    public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3, SDL_Renderer* render, SDL_Color color) : Figure(0, 0, color), x1(x1),
    y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), render(render)
    {}
    ~Triangle() override = default;
    void draw(SDL_Renderer* render) override
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
            }
        
    }
};

class Circle : public Figure
{
    private:
    int radius;
    int diameter;
    public:
    Circle(int x, int y, SDL_Color color, int radius) : Figure(x, y, color), radius(radius), diameter(radius * 2) {}
    void draw(SDL_Renderer* render) override
    {
        if(render == nullptr) return;
        SDL_SetRenderDrawColor(render, getColor().r, getColor().g, getColor().b, getColor().a);

        int x_pos = radius;
        int y_pos = 0;
        int err = 0;

        while (x_pos >= y_pos) {
        SDL_RenderDrawPoint(render, this->getX() + x_pos, this->getY() + y_pos);
        SDL_RenderDrawPoint(render, this->getX() + x_pos, this->getY() - y_pos);
        SDL_RenderDrawPoint(render, this->getX() - x_pos, this->getY() + y_pos);
        SDL_RenderDrawPoint(render, this->getX() - x_pos, this->getY() - y_pos);
        SDL_RenderDrawPoint(render, this->getX() + y_pos, this->getY() + x_pos);
        SDL_RenderDrawPoint(render, this->getX() + y_pos, this->getY() - x_pos);
        SDL_RenderDrawPoint(render, this->getX() - y_pos, this->getY() + x_pos);
        SDL_RenderDrawPoint(render, this->getX() - y_pos, this->getY() - x_pos);


        if (err <= x_pos) {
            y_pos++;
            err += (y_pos * 2 + 1);
        }

        if (err > y_pos) {
            x_pos--;
            err -= (x_pos * 2 + 1);
        }
    }
}
};



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

        SDL_SetRenderDrawColor(render, 255, 255, 255, 255); 
        SDL_RenderClear(render);
        SDL_Color green = {0, 255, 0, 255};
        
        Circle circle(300, 200, green, 100);
        circle.draw(render);
        SDL_RenderPresent(render);

    }
    quit();
    return 0;
}
