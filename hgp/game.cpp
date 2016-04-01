#include "game.h"
#include "gamemanager.h"
#include "common/displaymanager.h"
#include "common/framerate.h"
#include <iostream>

//#define TIME_PER_FRAME = 1.f/60.f;

RRG_Game::RRG_Game() {
}

RRG_Game::~RRG_Game() {
}

bool RRG_Game::Run(int argc, char* args[]) {
    RRG_EventManager& _eventManager = RRG_EventManager::Instance();
    RRG_DisplayManager& _displayManager = RRG_DisplayManager::Instance();
    RRG_GameManager& _gameManager = RRG_GameManager::Instance();

    if (!_eventManager.Initialize() || !_displayManager.Initialize() || !_gameManager.Initialize())
        return 1;

    _eventManager.Register<RRG_EventObserver::CloseEvent>([this](bool force_close) { _quit = OnClose(force_close); });
    _eventManager.Register<RRG_EventObserver::MouseMoveEvent>([this](RRG_MouseMoveEventArg arg) { OnMouseMove(arg); });

    RRG_FrameRate fps;
    RRG_Interval interval;
    RRG_Interval tempo;
    int sec = 0;
    int re = 0;
    unsigned long long rate = (1.f/60.f)*1000;
    while (!_quit) {
        _eventManager.DispatchEvent();

        if(interval.value() > rate)
        {
            if(_displayManager.BeginDraw())
                _gameManager.Update();
            _displayManager.DrawText(std::to_string(fps.Get()));
            _displayManager.FinishDraw();
            interval = RRG_Interval();
            re++;
            fps.Update();
        }

        //std::cout<<"Fps: "<<fps.Get()<<'\n';
        if(tempo.value() > 1000){
            sec++;
            std::cout<<"Secs: "<<sec<<'\n';
            std::cout<<"Renders: "<<re<<'\n';
            std::cout<<"Fps: "<<fps.Get()<<'\n';
            tempo = RRG_Interval();
            re = 0;
        }
    }

    return 0;
}

void RRG_Game::OnMouseMove(RRG_MouseMoveEventArg arg) {
}

bool RRG_Game::OnClose(bool force_close) {
    bool can_close = true;
    const bool closing{force_close || can_close};
    if (closing) {
        // Actually close the window.
        // ...  
    }
    return closing;
}


int main(int argc, char* args[]) {
    RRG_Game game;

    int result = game.Run(argc, args);

    return result;
}