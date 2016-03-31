#ifndef RRG_LOGINCONTROLLER_H
#define RRG_LOGINCONTROLLER_H

#include "viewcontroller.h"
#include "interface/button.h"

class RRG_LoginController : public RRG_ViewController {
public:
    RRG_LoginController();
    virtual ~RRG_LoginController();
private:
    RRG_Button* login_button;
    void LoginButton_MouseOver();
    void LoginButton_MouseOut();

};

#endif
