#include "deepg.h"

Timer::Timer() : run(false), start_time(0), stop_time(0)
{}

Timer::~Timer(){}

void Timer::start()
{
    run = true;
    start_time = SDL_GetTicks();
}
void Timer::stop()
{
    run = false;
    stop_time = SDL_GetTicks();
}
void Timer::restart()
{
    this->stop();
    this->start();
}
Uint32 Timer::getTime() const
{
    return (SDL_GetTicks() - start_time);
}

bool Timer::IsRunning() const
{
    return run;
}