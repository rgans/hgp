#include "gamemanager.h"
#include "logincontroller.h"

RRG_GameManager::RRG_GameManager()
{
}


RRG_GameManager::~RRG_GameManager()
{
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
    RRG_LoginController _currentController;
    _currentController.Render();
}