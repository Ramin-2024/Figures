//после окончания основной работы не забудь добавить SDL2.dll в сборку cmake или в папку build
#include <SDL2/SDL.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "Shapes.h"
#include "Figure.h"
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
        return false; //
    }
    return true;
}
void quit()
{
    if(render != nullptr) SDL_DestroyRenderer(render);
    if(window != nullptr) SDL_DestroyWindow(window);
    SDL_Quit();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    sdl_init("Window", WIDTH, HEIGHT);
    bool running = true;
    SDL_Event event;
    SDL_Color green = {0, 255, 0, 255};
    CustomForm cust(green);
    //Rect rect(50, 100, 100, 350, green);
    //Triangle trio(200, 50, 300, 50, 400, 100, render, green);
    Cub cub(100, 200, 300, green);
    Cub cub2(200, 300, 350, green);
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                cust.line = true;
                SDL_MouseButtonEvent* mouse = (SDL_MouseButtonEvent*)&event;
                cust.addPoint({mouse->x, mouse->y});
                
               
            }
            else if(event.type == SDL_KEYDOWN)
                {
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_e:
                        cust.fill = true;
                        break;
                    }
                }
        }

        SDL_SetRenderDrawColor(render, 255, 255, 255, 255); 
        SDL_RenderClear(render);

        cub.draw(render);
        cub2.draw(render);
        cust.draw(render);
        SDL_RenderPresent(render);

    }

    quit();
    return 0;
}
