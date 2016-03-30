#ifndef RRG_DISPLAYMANAGER_H
#define RRG_DISPLAYMANAGER_H

#include <SDL2/SDL.h>
#include "util/observer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

typedef struct RRG_Size
{
	float width;
	float height;
	RRG_Size(){};
	RRG_Size(float width_, float height_) : width(width_), height(height_){};
} RRG_Size;

typedef struct RRG_Point
{
	float x;
	float y;
	RRG_Point(){};
	RRG_Point(float x_, float y_) : x(x_), y(y_){};
} RRG_Point;

typedef struct RRG_Frame
{
	RRG_Size size;
	RRG_Point position;
	RRG_Frame(){};
	RRG_Frame(float x_, float y_, float w_, float h_) : position(RRG_Point(x_, y_)), size(RRG_Size(w_, h_)){};
} RRG_Frame;

struct RRG_DisplayObserver {
	enum { MouseMoveEvent, MouseClickEvent, KeyDownEvent, KeyUpEvent, KeyPressEvent };
	using ObserverTable = std::tuple<
		RRG_Observer<void()> //MouseMoveEvent
	>;
};

class RRG_DisplayManager : public RRG_Observable<RRG_DisplayObserver>
{
public:
	static RRG_DisplayManager& Instance()
	{
		static RRG_DisplayManager _instance;
		return _instance;
	}

	RRG_DisplayManager(RRG_DisplayManager const&) = delete;
	void operator=(RRG_DisplayManager const&) = delete;

	bool Initialize();

	void DrawImage();
	void DrawText();
	void DrawLine(const RRG_Frame& frame, Uint32 color);
	void Draw(const RRG_Frame& frame, Uint32 color);
	void Clear(Uint32 color);
	void ClearAll(Uint32 color);
	bool SetMousePosition(const RRG_Point& position);
	//bool SetMouseCursor(csMouseCursorID iShape);
	//bool SetMouseCursor(iImage *image, const csRGBcolor* keycolor = 0, int hotspot_x = 0, int hotspot_y = 0, csRGBcolor fg = csRGBcolor(255, 255, 255), csRGBcolor bg = csRGBcolor(0, 0, 0));

	void Render();

private:
	RRG_DisplayManager();
	~RRG_DisplayManager();

	bool BeginDraw();
	void FinishDraw();
        
	SDL_Window* _window;
	SDL_Surface* _screenSurface;
	bool _initialized;
};

#endif