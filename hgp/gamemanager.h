#ifndef RRG_GAMEMANAGER_H
#define RRG_GAMEMANAGER_H

#include "common/util/observer.h"
#include "logincontroller.h"

struct RRG_GameObserver {
	enum { CloseEvent, MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent };
	using ObserverTable = std::tuple<
		RRG_Observer<void(bool force_close)>
	>;
};

class RRG_GameManager : public RRG_Observable<RRG_GameObserver>
{
public:
	static RRG_GameManager& Instance()
	{
		static RRG_GameManager _instance;
		return _instance;
	}

	RRG_GameManager(RRG_GameManager const&) = delete;
	void operator=(RRG_GameManager const&) = delete;

	bool Initialize();
	void Update();

private:
	RRG_GameManager();
	~RRG_GameManager();

	bool _initialized;
        RRG_LoginController* _currentController;
};

#endif

