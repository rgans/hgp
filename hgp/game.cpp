#include "game.h"
#include <iostream>

RRG_Game::RRG_Game()
{
	_quit = false;
}


RRG_Game::~RRG_Game()
{
}

bool RRG_Game::Run(int argc, char* args[])
{
	RRG_EventManager& _eventManager = RRG_EventManager::Instance();
	RRG_DisplayManager& _displayManager = RRG_DisplayManager::Instance();

	if (!_eventManager.Initialize()) {
		return 1;
	}
	else if (!_displayManager.Initialize()){
		return 1;
	}

	_eventManager.Register<RRG_EventObserver::CloseEvent>([this](bool force_close){ _quit = OnClose(force_close); });
	_eventManager.Register<RRG_EventObserver::MouseMoveEvent>([this](RRG_MouseMoveEventArg arg){ OnMouseMove(arg); });

	while (!_quit)
	{
		_eventManager.DispatchEvent();
		_displayManager.Render();
	}

	return 0;
}

void RRG_Game::OnMouseMove(RRG_MouseMoveEventArg arg)
{
}

bool RRG_Game::OnClose(bool force_close)
{
	bool can_close = true;
	const bool closing{ force_close || can_close };
	if (closing) {
		// Actually close the window.
		// ...  
	}
	return closing;
}

int main(int argc, char* args[])
{
	RRG_Game* game = new RRG_Game();

	int result = game->Run(argc, args);

	delete game;

	return result;
}