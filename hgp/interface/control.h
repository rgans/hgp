#ifndef RRG_CONTROL_H
#define RRG_CONTROL_H

#include "view.h"

class RRG_Control : public RRG_View {
public:
    RRG_Control();
    ~RRG_Control();

    inline bool IsEnabled() {
        return _enabled;
    };

    inline void SetEnabled(bool enabled) {
        _enabled = enabled;
    };

private:
    bool _enabled = true;

protected:
};

#endif