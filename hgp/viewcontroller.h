#ifndef RRG_VIEWCONTROLLER_H
#define RRG_VIEWCONTROLLER_H

#include "interface/view.h"

class RRG_ViewController {
public:
    RRG_ViewController();
    virtual ~RRG_ViewController();
    virtual void Render();

protected:

    RRG_View* GetView() { return &_view; };

private:
    RRG_View _view;

};

#endif

