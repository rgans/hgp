#include "viewcontroller.h"

RRG_ViewController::RRG_ViewController() {
    //_view = new RRG_View();
}

RRG_ViewController::~RRG_ViewController() {
}

void RRG_ViewController::Render() {
    _view.Render();
}
