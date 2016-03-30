#ifndef RRG_CONTROL_H
#define RRG_CONTROL_H

#include "widget.h"
#include "../common/displaymanager.h"

class RRG_Control : public RRG_Widget
{
public:
	RRG_Control();
	~RRG_Control();

	inline RRG_Control* GetParent() { return _parent; };

	inline const RRG_Frame& GetFrame() { return _frame; };
	inline void SetFrame(const RRG_Frame* frame) { _frame.position = frame->position; _frame.size = frame->size; Resize(); };

	inline bool IsEnabled() { return _enabled; };
	inline void SetEnabled(bool enabled) { _enabled = enabled; };

	inline bool IsVisible() { return _visible && (!_parent || _parent->IsVisible()); }
	inline void SetVisibility(bool visible) { if (visible) Show(); else Hide(); }

private:
	RRG_Control* _parent;
	bool _need_layout;
	bool _visible;
	bool _enabled;
	RRG_Frame _frame = RRG_Frame(0.0, 0.0, 10.0, 10.0);
	RRG_DisplayManager& _displayManager = RRG_DisplayManager::Instance();

protected:
	virtual void Show();
	virtual void Hide();
	virtual void Resize();
	virtual void Draw();
};

#endif