#include "gamemanager.h"
#include "logincontroller.h"

RRG_GameManager::RRG_GameManager()
{
	_initialized = false;
        
        _currentController = new RRG_LoginController();
}


RRG_GameManager::~RRG_GameManager()
{
    delete _currentController;
}

bool RRG_GameManager::Initialize()
{
	if (!_initialized){
		_initialized = true;
	}

	return _initialized;
}

void RRG_GameManager::Update()
{
    _currentController->Render();
}