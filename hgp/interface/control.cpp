#include "control.h"

RRG_Control::RRG_Control()
{
}


RRG_Control::~RRG_Control()
{
}

void RRG_Control::Show()
{
	_visible = true;
}

void RRG_Control::Hide()
{
	_visible = false;
}

void RRG_Control::Resize()
{
}

void RRG_Control::Draw()
{
	_displayManager.Draw(&_frame, 1);
}