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
    
    for(int i = 0; i < _child.size(); i++){
        RRG_View* child = _child.at(i);
        child->Render();
    }
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
    _displayManager.Draw(_frame, _background_color);
}

bool RRG_View::IsInside(const RRG_Point* point)
{
    if(!point)
        return false;
    
    return point->x >= _frame.position.x && 
            point->x <= _frame.size.width && 
            point->y >= _frame.position.y && 
            point->y <= _frame.size.height;
}