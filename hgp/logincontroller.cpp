#include "logincontroller.h"

RRG_LoginController::RRG_LoginController() {
    RRG_View* _mainView = GetView();
    login_button = new RRG_Button();
    login_button->Register<RRG_ControlObserver::MouseOverEvent>([this]() { LoginButton_MouseOver(); });
    login_button->Register<RRG_ControlObserver::MouseOutEvent>([this]() { LoginButton_MouseOut(); });
    
    _mainView->AddChild(login_button);
}

RRG_LoginController::~RRG_LoginController() {
    delete login_button;
}

void RRG_LoginController::LoginButton_MouseOver(){
    RRG_Color over_color = RRG_Color(255, 0, 0);
    login_button->SetBackgroundColor(over_color);
}
void RRG_LoginController::LoginButton_MouseOut(){
    RRG_Color out_color = RRG_Color(0, 255, 0);
    login_button->SetBackgroundColor(out_color);
}
