#ifndef RRG_CONTROL_H
#define RRG_CONTROL_H

#include "view.h"
#include "../common/eventmanager.h"

struct RRG_ControlObserver {

    enum { MouseOverEvent, MouseOutEvent, MouseClickEvent };
    using ObserverTable = std::tuple<
            RRG_Observer<void()>, //MouseOverEvent
            RRG_Observer<void()> //MouseOutEvent
    >;
};

class RRG_Control : public RRG_View, public RRG_Observable<RRG_ControlObserver> {
public:
    RRG_Control();
    ~RRG_Control();

    inline bool IsEnabled() {
        return _enabled;
    };

    inline void SetEnabled(bool enabled) {
        _enabled = enabled;
    };

private:
    bool _enabled = true;
    bool _mouseover = false;

    void OnMouseMove(RRG_MouseMoveEventArg arg);

protected:
};

#endif