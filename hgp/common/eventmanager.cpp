#include "EventManager.h"

RRG_EventManager::RRG_EventManager()
{
	_initialized = false;
}


RRG_EventManager::~RRG_EventManager()
{
}

bool RRG_EventManager::Initialize()
{
	if (!_initialized){
		_initialized = !(SDL_Init(SDL_INIT_EVENTS) < 0);
	}

	return _initialized;
}

void RRG_EventManager::DispatchEvent()
{
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			HandleClose();
		}
		//User requests quit
		else if (e.type == SDL_WINDOWEVENT)
		{
			//HandleMouseEvent();
		}
		else if (e.type == SDL_SYSWMEVENT)
		{
			//HandleKeyboardEvent();
		}
		else if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEWHEEL)
		{
			HandleMouseEvent();
		}
		else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP || e.type == SDL_TEXTEDITING || e.type == SDL_TEXTINPUT)
		{
			HandleKeyboardEvent();
		}
	}
}

void RRG_EventManager::HandleClose()
{
	Notify<RRG_EventObserver::CloseEvent>(false);
}

void RRG_EventManager::HandleMouseEvent()
{
	switch (e.type)
	{
	case SDL_MOUSEMOTION:
		Notify<RRG_EventObserver::MouseMoveEvent>(RRG_MouseMoveEventArg(e.motion.x, e.motion.y));
	break;
	case SDL_MOUSEBUTTONDOWN:
		//Notify<CEventObserver::MouseMoveEvent>();
	break;
	case SDL_MOUSEBUTTONUP:
		//Notify<CEventObserver::MouseMoveEvent>();
	break;
	case SDL_MOUSEWHEEL:
		//Notify<CEventObserver::MouseMoveEvent>();
	break;
	default:
	break;
	}
}

void RRG_EventManager::HandleKeyboardEvent()
{
	//Notify<CEventObserver::KeyPressEvent>();
}