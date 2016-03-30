#ifndef RRG_INPUTMANAGER_H
#define RRG_INPUTMANAGER_H

#include "util/observer.h"

struct RRG_InputObserver {
	enum { MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent };
	using ObserverTable = std::tuple<
		RRG_Observer<void()> //MouseMoveEvent
	>;
};

class RRG_InputManager : public RRG_Observable<RRG_InputObserver>
{
public:
	static RRG_InputManager& Instance()
	{
		static RRG_InputManager _instance;
		return _instance;
	}

	RRG_InputManager(RRG_InputManager const&) = delete;
	void operator=(RRG_InputManager const&) = delete;

	void HandleInput();
	bool Initialize();

private:
	RRG_InputManager();
	~RRG_InputManager();

	void HandleMouseEvent();
	void HandleKeyboardEvent();
};

#endif