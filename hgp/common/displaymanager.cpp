#include <SDL2/SDL.h>

#include "displaymanager.h"

RRG_DisplayManager::RRG_DisplayManager() {
    _initialized = false;
}

RRG_DisplayManager::~RRG_DisplayManager() {
    SDL_FreeSurface(_screenSurface);
    
    SDL_DestroyRenderer(renderer);
    
    //Destroy window
    SDL_DestroyWindow(_window);

    TTF_Quit();
    //Quit SDL subsystems
    SDL_Quit();
}

bool RRG_DisplayManager::Initialize() {
    if (!_initialized) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        } else {
            //Create window
            _window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
            if (_window == NULL) {
                printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            } else {
                TTF_Init();
                renderer = SDL_CreateRenderer(_window, -1, 0);
                //Get window surface
                _screenSurface = SDL_GetWindowSurface(_window);

                Clear(_clear_color);
                
                //Fill the surface white
                //SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));

                //SDL_UpdateWindowSurface(_window);

                _initialized = true;
            }
        }
    }

    return _initialized;
}

void RRG_DisplayManager::DrawImage() {
}

void RRG_DisplayManager::DrawText(std::string text) {
    TTF_Font* Sans = TTF_OpenFont("Aaargh.ttf", 24);
    SDL_Color textColor = { 0, 0, 0, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(Sans, text.c_str(), textColor);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    int text_width = textSurface->w;
    int text_height = textSurface->h;

    SDL_FreeSurface(textSurface);

    SDL_Rect renderQuad = { 20, 20, text_width, text_height };
    SDL_RenderCopy(renderer, textTexture, NULL, &renderQuad);

    SDL_DestroyTexture(textTexture);
}

void RRG_DisplayManager::DrawLine(const RRG_Frame& frame, const RRG_Color& color) {
}

void RRG_DisplayManager::Draw(const RRG_Frame& frame, const RRG_Color& color) {
    SDL_Rect rect = { int(frame.position.x), int(frame.position.y), int(frame.size.width), int(frame.size.height) };

    SDL_FillRect(_screenSurface, &rect, createRGBA(color));
}

void RRG_DisplayManager::Clear(const RRG_Color& color) {
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    SDL_RenderClear(renderer);
}

void RRG_DisplayManager::ClearAll(const RRG_Color& color) {
}

bool RRG_DisplayManager::SetMousePosition(const RRG_Point& position) {
    return true;
}
//bool SetMouseCursor(csMouseCursorID iShape);
//bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

bool RRG_DisplayManager::BeginDraw() {
    //SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
    Clear(_clear_color);
    return true;
}

void RRG_DisplayManager::FinishDraw() {
    SDL_RenderPresent(renderer);
    //SDL_UpdateWindowSurface(_window);
}

void RRG_DisplayManager::Render() {
    //BeginDraw();
    //FinishDraw();
    SDL_UpdateWindowSurface(_window);
}