#ifndef RRG_GAME_H
#define RRG_GAME_H

#include "common/eventmanager.h"
#include "common/displaymanager.h"
#include <SDL2/SDL.h>

class RRG_Game
{
public:
	RRG_Game();
	~RRG_Game();

	bool Run(int argc, char* args[]);

private:
	bool Initialize();
	bool Refresh();
	bool Update();
	bool Render();
	void Cleanup();

	void OnMouseMove(RRG_MouseMoveEventArg arg);
	bool OnClose(bool force_close = false);

	bool _quit;
};

#endif