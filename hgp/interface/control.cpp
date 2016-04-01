#include "control.h"

RRG_Control::RRG_Control() {
    RRG_EventManager& _eventManager = RRG_EventManager::Instance();

    _eventManager.Register<RRG_EventObserver::MouseMoveEvent>([this](RRG_MouseMoveEventArg arg) { OnMouseMove(arg); });
}

RRG_Control::~RRG_Control() {
}

void RRG_Control::OnMouseMove(RRG_MouseMoveEventArg arg)
{
    RRG_Point _point = { arg.x, arg.y };
    if(IsInside(&_point))
    {
        Notify<RRG_ControlObserver::MouseOverEvent>();
        _mouseover = true;
    } else if(_mouseover) {
        Notify<RRG_ControlObserver::MouseOutEvent>();
        _mouseover = false;
    }
}