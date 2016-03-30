#ifndef RRG_GAMECONTROLLER_H
#define RRG_GAMECONTROLLER_H

#include "common/util/observer.h"

struct RRG_ControllerObserver {
	enum { QuitGameEvent, LoadGameEvent, OpenLoginViewEvent, OpenCharacterSelectViewEvent, EnterGameEvent };
	using ObserverTable = std::tuple<
		RRG_Observer<void()> //MouseMoveEvent
	>;
};

class RRG_GameController : public RRG_Observable<RRG_ControllerObserver> {
public:
    RRG_GameController();
    virtual ~RRG_GameController();
    
    void Update();
    
private:

};

#endif

