#include "deepg.h"

Evenement::Evenement() : quit(false)
{
    this->initTabKey();
}

Evenement::~Evenement()
{}

void Evenement::initTabKey()
{
    for(int i = 0; i<KEY_DOWN+1; i++)
        for(int j = 0; j<KEY_END; j++)
            TabKey[i][j] = false;
}

void Evenement::UpdateEvent()
{
    this->initTabKey();

    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                this->setTabKey(event.key.keysym.sym, KEY_DOWN);
                break;
            case SDL_KEYUP:
                this->setTabKey(event.key.keysym.sym, KEY_UP);
                break;
        }
    }
}

bool Evenement::IsKeyPressed(const int UpDown, const int Dir) const
{
    return TabKey[UpDown][Dir];
}

void Evenement::setTabKey(SDL_Keycode sym, const int UD)
{
    if(sym == SDLK_z || sym == SDLK_UP)
        TabKey[UD][KEY_FORWARD] = true;
    if(sym == SDLK_q || sym == SDLK_LEFT)
        TabKey[UD][KEY_LEFT] = true;
    if(sym == SDLK_s || sym == SDLK_DOWN)
        TabKey[UD][KEY_BACKWARD] = true;
    if(sym == SDLK_d || sym == SDLK_RIGHT)
        TabKey[UD][KEY_RIGHT] = true;
    if(sym == SDLK_ESCAPE)
        quit = true;
}