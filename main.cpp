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

bool square(SDL_Renderer* renders, int x, int y, int width, int height)
{
    if(renders == nullptr) return false;
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    SDL_SetRenderDrawColor(renders, 55, 85, 100, 125);
    if(SDL_RenderFillRect(renders, &rect) != 0) 
    {
        std::cout << "Render Falled!!!" << std::endl;
        return false;
    }
    return true; ///
}

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

        SDL_SetRenderDrawColor(render, 255, 0, 0, 255); // Красный цвет для треугольника
        triangle(render, 320, 173, 253, 283, 387, 283);
        square(render, 250, 120, 100, 100);

        SDL_RenderPresent(render); 
    }
    quit();
    return 0;
}
