#include "InputManager.h"
#include <SDL.h>

bool _initialized;

RRG_InputManager::RRG_InputManager()
{
	_initialized = false;
}


RRG_InputManager::~RRG_InputManager()
{
}

bool RRG_InputManager::Initialize()
{
	if (!_initialized){
		_initialized = SDL_Init(SDL_INIT_EVENTS) < 0;
	}

	return _initialized;
}

void RRG_InputManager::HandleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEWHEEL)
		{
			HandleMouseEvent();
		}
		else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP || e.type == SDL_TEXTEDITING || e.type == SDL_TEXTINPUT)
		{
			HandleKeyboardEvent();
		}
	}
}

void RRG_InputManager::HandleMouseEvent()
{
	Notify<RRG_InputObserver::MouseMoveEvent>();

	/*
	switch (e.type)
	{
	case SDL_MOUSEMOTION:
		Notify<CInputObserver::MouseMoveEvent>();
		break;
	case SDL_MOUSEBUTTONDOWN:
		Notify<CInputObserver::MouseMoveEvent>();
		break;
	case SDL_MOUSEBUTTONUP:
		Notify<CInputObserver::MouseMoveEvent>();
		break;
	case SDL_MOUSEWHEEL:
		Notify<CInputObserver::MouseMoveEvent>();
		break;
	default:
		break;
	}
	*/
}

void RRG_InputManager::HandleKeyboardEvent()
{
	//Notify<CInputObserver::KeyPressEvent>();
}