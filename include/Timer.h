#ifndef TIMER_H
#define TIMER_H

#include "deepg.h"

class Timer
{
private:
    bool run;
    Uint32 start_time;
    Uint32 stop_time;
public:
    Timer();
    ~Timer();
    void Timer_start();
    void Timer_stop();
    void Timer_restart();
    //retourne la valeur du timer en milliseconde
    Uint32 Timer_getTime() const; 
    bool Timer_IsRunning() const;

};


#endif