#include "deepg.h"

Animation::Animation(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, Sprite* _sprite): Main_Renderer(_Main_Renderer), framerate(_framerate), AnimFile(_AnimFile), sprite(_sprite)
{
    int i = 0;
    SDL_Surface* Surface = IMG_Load((AnimFile + std::to_string(i) + ".png").c_str());
    SDL_Texture* texture;
    sprite->setHitbox_wh(Surface->w, Surface->h);
    while(Surface)
    {
        texture = SDL_CreateTextureFromSurface(Main_Renderer,Surface);
        if(texture)
        {
            Textures.push_back(texture);
            i++;
            Surface = IMG_Load((AnimFile + std::to_string(i) + ".png").c_str());
        }
        else
            SDL_Log("Unable to create texture : %s", SDL_GetError());
        
    }
}
Animation::Animation() : Main_Renderer(nullptr), framerate(0), AnimFile(""), sprite(nullptr)
{}

Animation::~Animation()
{
    for(int i = 0; i < Textures.size(); i++)
        SDL_DestroyTexture(Textures[i]);
}


void Animation::Update_Texture()
{
    if(!this->Timer_IsRunning())
        this->Timer_restart();
    if(this->Timer_getTime() >= (1.0/framerate)*1000)
    {
        this->Timer_restart();
        frame++;
        if(frame >= Textures.size() || statique) //Soit on loop l'animation soit on est statique
            frame = 0;
    }
    sprite->setSprite_Texture(Textures[frame]);
}