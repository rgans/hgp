#include "view.h"


RRG_View::RRG_View()
{
}


RRG_View::~RRG_View()
{
}

void RRG_View::Render() {
    Resize();
    Draw();
}

void RRG_View::Show() {
    _visible = true;
}

void RRG_View::Hide() {
    _visible = false;
}

void RRG_View::Resize() {
}

void RRG_View::Draw() {
    _displayManager.Draw(_frame, 1);
}