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
    void start();
    void stop();
    void restart();
    //retourne la valeur du timer en milliseconde
    Uint32 getTime() const; 
    bool IsRunning() const;

};


#endif