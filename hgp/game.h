#ifndef RRG_GAME_H
#define RRG_GAME_H

#include "common/eventmanager.h"

namespace RRG {

    class Game {
    public:
        Game();
        ~Game();

        bool Run(int argc, char* args[]);

    private:
        bool Initialize();
        bool Refresh();
        bool Update();
        bool Render();
        void Cleanup();

        void OnMouseMove(MouseMoveEventArg arg);
        bool OnClose(bool force_close = false);

        bool _quit = false;
    };

}

#endif