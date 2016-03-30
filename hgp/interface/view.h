#ifndef RRG_VIEW_H
#define RRG_VIEW_H

#include "control.h"

// Defines observers for Windows class.
/*
struct CWindowObservers {
	enum { ShowEvent, CloseEvent };
	using ObserverTable = std::tuple<
		CObserver<void()>,                 // ShowEvent
		CObserver<bool(bool force_close)>  // CloseEvent
	>;
};
: public CObservable<CWindowObservers>
*/

class RRG_View : public RRG_Control
{
public:
	RRG_View();
	~RRG_View();

protected:

private:

};

#endif