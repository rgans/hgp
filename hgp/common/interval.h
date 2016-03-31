#ifndef RRG_INTERVAL_H
#define RRG_INTERVAL_H

#include <chrono>

class RRG_Interval {
public:
    RRG_Interval();
    virtual ~RRG_Interval();

    inline unsigned int value() const 
    {
        return GetTickCount()-initial_;
    }
    
    static unsigned long long
    GetTickCount()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
    }
    
private:
    unsigned int initial_;

};

struct TickCountClock
{
    typedef unsigned long long                       rep;
    typedef std::milli                               period;
    typedef std::chrono::duration<rep, period>       duration;
    typedef std::chrono::time_point<TickCountClock>  time_point;
    static const bool is_steady =                    true;

    static time_point now() noexcept
    {
        return time_point(duration(RRG_Interval::GetTickCount()));
    }
};

#endif

