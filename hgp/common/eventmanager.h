#ifndef RRG_EVENTMANAGER_H
#define RRG_EVENTMANAGER_H

#include "util/observer.h"
#include <SDL2/SDL.h>

typedef struct RRG_MouseMoveEventArg {
	float x;
	float y;
	RRG_MouseMoveEventArg(float x_, float y_) : x(x_), y(y_){};
} RRG_MouseMoveEventArg;

struct RRG_EventObserver {
	enum { CloseEvent, MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent };
	using ObserverTable = std::tuple<
		RRG_Observer<void(bool force_close)>, //CloseEvent
		RRG_Observer<void(RRG_MouseMoveEventArg arg)> //MouseMoveEvent
	>;
};

class RRG_EventManager : public RRG_Observable<RRG_EventObserver>
{
public:
	static RRG_EventManager& Instance()
	{
		static RRG_EventManager _instance;
		return _instance;
	}

	RRG_EventManager(RRG_EventManager const&) = delete;
	void operator=(RRG_EventManager const&) = delete;

	bool Initialize();
	void DispatchEvent();

private:
	RRG_EventManager();
	~RRG_EventManager();

	void HandleClose();
	void HandleMouseEvent();
	void HandleKeyboardEvent();

	SDL_Event e;
	bool _initialized;
};

#endif