#ifndef RRG_VIEW_H
#define RRG_VIEW_H

#include "../common/displaymanager.h"
#include <iostream>

class RRG_View
{
public:
	RRG_View();
	virtual ~RRG_View();
        
    inline RRG_View* GetParent() {
        return _parent;
    };

    inline const RRG_Frame& GetFrame() {
        return _frame;
    };

    inline void SetFrame(const RRG_Frame& frame) {
        _frame.position.x = frame.position.x;
        _frame.position.y = frame.position.y;
        _frame.size.width = frame.size.width;
        _frame.size.height = frame.size.height;
    };
    
    inline const RRG_Color& GetBackgroundColor() {
        return _background_color;
    };

    inline void SetBackgroundColor(const RRG_Color& color) {
        _background_color.r = color.r;
        _background_color.g = color.g;
        _background_color.b = color.b;
        _background_color.a = color.a;
    };
    
    inline bool IsVisible() {
        return _visible && (!_parent || _parent->IsVisible());
    }

    inline void SetVisibility(bool visible) {
        if (visible) Show();
        else Hide();
    }
    
    inline void AddChild(RRG_View* view) {
        if(!view)
            return;

        _child.push_back(view);

        view->SetParent(this);
    }
    
    inline void RemoveChild(RRG_View* view) {
        if(!view)
            return;

        //_child.erase(&view);

        view->SetParent(nullptr);
    }
    

    
    virtual void Render();
    
private:
    RRG_View* _parent = nullptr;
    std::vector<RRG_View*> _child;
    bool _need_layout = false;
    bool _visible = true;
    RRG_Color _background_color = { 0, 0, 0, 0 };
    RRG_Frame _frame = { 0.f, 0.f, 100.f, 100.f };
    RRG_DisplayManager& _displayManager = RRG_DisplayManager::Instance();

protected:
    inline void SetParent(RRG_View* parent) { _parent = parent; };
    
    virtual void Show();
    virtual void Hide();
    virtual void Resize();
    virtual void Draw();
    
    bool IsInside(const RRG_Point* point);
};

#endif