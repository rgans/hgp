#include "game.h"
#include "gamemanager.h"
#include "common/displaymanager.h"
#include "common/framerate.h"
#include <iostream>

//#define TIME_PER_FRAME = 1.f/60.f;

RRG_Game::RRG_Game() {
    _quit = false;
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
    unsigned int timeSinceLastUpdate = fps.Get();
    unsigned int TimePerFrame = 1.f/60.f;
    while (!_quit) {
        
//        sf::Time elapsedTime = clock.restart();
//        timeSinceLastUpdate += elapsedTime;
        timeSinceLastUpdate = fps.Get();
        
        while (timeSinceLastUpdate > TimePerFrame){
            _eventManager.DispatchEvent();
            if(_displayManager.BeginDraw())
                _gameManager.Update();
            
            _displayManager.DrawText(std::to_string(timeSinceLastUpdate));
        }

//        updateStatistics(elapsedTime);        
        _displayManager.FinishDraw();
        
        fps.Update();
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
    RRG_Game* game = new RRG_Game();

    int result = game->Run(argc, args);

    delete game;

    return result;
}