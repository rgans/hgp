#include "displaymanager.h"

RRG_DisplayManager::RRG_DisplayManager() {
    _initialized = false;
}

RRG_DisplayManager::~RRG_DisplayManager() {
    //Destroy window
    SDL_DestroyWindow(_window);

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
                //Get window surface
                _screenSurface = SDL_GetWindowSurface(_window);

                //Fill the surface white
                SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));

                SDL_UpdateWindowSurface(_window);

                _initialized = true;
            }
        }
    }

    return _initialized;
}

void RRG_DisplayManager::DrawImage() {
}

void RRG_DisplayManager::DrawText() {
}

void RRG_DisplayManager::DrawLine(const RRG_Frame& frame, Uint32 color) {
}

void RRG_DisplayManager::Draw(const RRG_Frame& frame, Uint32 color) {
    SDL_Rect rect;
    rect.x = frame.position.x;
    rect.y = frame.position.y;
    rect.w = frame.size.width;
    rect.h = frame.size.height;

    SDL_FillRect(_screenSurface, &rect, color);
}

void RRG_DisplayManager::Clear(Uint32 color) {
}

void RRG_DisplayManager::ClearAll(Uint32 color) {
}

bool RRG_DisplayManager::SetMousePosition(const RRG_Point& position) {
    return true;
}
//bool SetMouseCursor(csMouseCursorID iShape);
//bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

bool RRG_DisplayManager::BeginDraw() {
    return SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
}

void RRG_DisplayManager::FinishDraw() {
    SDL_UpdateWindowSurface(_window);
}

void RRG_DisplayManager::Render() {
    BeginDraw();
    FinishDraw();
}