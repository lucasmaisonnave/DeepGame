#include "deepg.h"

Timer::Timer() : run(false), start_time(0), stop_time(0)
{}

Timer::~Timer(){}

void Timer::Timer_start()
{
    run = true;
    start_time = SDL_GetTicks();
}
void Timer::Timer_stop()
{
    run = false;
    stop_time = SDL_GetTicks();
}
void Timer::Timer_restart()
{
    this->Timer_stop();
    this->Timer_start();
}
Uint32 Timer::Timer_getTime() const
{
    return (SDL_GetTicks() - start_time);
}

bool Timer::Timer_IsRunning() const
{
    return run;
}