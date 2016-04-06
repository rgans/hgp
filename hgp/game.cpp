#include "game.h"
#include "gamemanager.h"
#include "common/displaymanager.h"
#include "common/framerate.h"
#include <iostream>

//#define TIME_PER_FRAME = 1.f/60.f;

RRG::Game::Game() {
}

RRG::Game::~Game() {
}

bool RRG::Game::Run(int argc, char* args[]) {
    RRG::EventManager& _eventManager = RRG::EventManager::Instance();
    RRG::DisplayManager& _displayManager = RRG::DisplayManager::Instance();
    RRG::GameManager& _gameManager = RRG::GameManager::Instance();

    if (!_eventManager.Initialize() || !_displayManager.Initialize() || !_gameManager.Initialize())
        return 1;

    _eventManager.Register<RRG::EventObserver::CloseEvent>([this](bool force_close) {
        _quit = OnClose(force_close); });
    _eventManager.Register<RRG::EventObserver::MouseMoveEvent>([this](RRG::MouseMoveEventArg arg) {
        OnMouseMove(arg); });

    RRG::FrameRate fps;
    RRG::Interval interval;
    RRG::Interval tempo;
    int sec = 0;
    int re = 0;
    unsigned long long rate = (1.f / 60.f)*1000;
    while (!_quit) {
        _eventManager.DispatchEvent();

        if (interval.value() > rate) {
            if (_displayManager.BeginDraw())
                _gameManager.Update();
//            _displayManager.DrawText(std::to_string(fps.Get()));
            _displayManager.FinishDraw();
            interval = RRG::Interval();
            re++;
            fps.Update();
        }

        //std::cout<<"Fps: "<<fps.Get()<<'\n';
        if (tempo.value() > 1000) {
            sec++;
            std::cout << "Secs: " << sec << '\n';
            std::cout << "Renders: " << re << '\n';
            std::cout << "Fps: " << fps.Get() << '\n';
            tempo = RRG::Interval();
            re = 0;
        }
    }

    return 0;
}

void RRG::Game::OnMouseMove(RRG::MouseMoveEventArg arg) {
}

bool RRG::Game::OnClose(bool force_close) {
    bool can_close = true;
    const bool closing{force_close || can_close};
    if (closing) {
        // Actually close the window.
        // ...  
    }
    return closing;
}

int main(int argc, char* args[]) {
    RRG::Game game;

    int result = game.Run(argc, args);

    return result;
}