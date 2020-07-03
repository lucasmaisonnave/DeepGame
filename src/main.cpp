#include "../include/deepg.h"


int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_Log("Unable to initialize SDL : %s", SDL_GetError());
    if(TTF_Init() != 0)
        SDL_Log("Unable to initialize TTF : %s", TTF_GetError());

    Game DeepGame;
    DeepGame.run();

    return 0;
}