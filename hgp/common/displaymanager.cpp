#include "displaymanager.h"

RRG::DisplayManager::DisplayManager() {
    _initialized = false;
}

RRG::DisplayManager::~DisplayManager() {
}

bool RRG::DisplayManager::Initialize() {
    if (!_initialized) {
    }

    return _initialized;
}

void RRG::DisplayManager::DrawImage() {
}

void RRG::DisplayManager::DrawText() {
}

void RRG::DisplayManager::DrawLine(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Draw(const RRG::Frame& frame, const RRG::Color& color) {
}

void RRG::DisplayManager::Clear(const RRG::Color& color) {
}

void RRG::DisplayManager::ClearAll(const RRG::Color& color) {
}

bool RRG::DisplayManager::SetMousePosition(const RRG::Point& position) {
    return true;
}
//bool SetMouseCursor(csMouseCursorID iShape);
//bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

bool RRG::DisplayManager::BeginDraw() {
    Clear(_clear_color);
    return true;
}

void RRG::DisplayManager::FinishDraw() {
}

void RRG::DisplayManager::Render() {
    //BeginDraw();
    //FinishDraw();
}