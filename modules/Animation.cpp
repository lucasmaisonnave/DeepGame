#include "deepg.h"
#include "Sprite.h"

Animation::Animation(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut) : Main_Renderer(_Main_Renderer), AnimFile(_AnimFile), framerate(_framerate), frame(0), direction_x(DROITE), direction_y(DROITE),
Sprite::Sprite(_Statut)
{
    SDL_Surface* Surface = nullptr;
    for(int i = 0; i<2; i++)
    {
        std::string direction = "/droite";
        std::string run = "/run_";
        if(i != 0)
            direction = "/gauche";
        for(int j = 0; j<IPA; j++)
        {
            std::string nbr = "f"+std::to_string(j);
            Surface = IMG_Load((AnimFile + direction + run + nbr + ".png").c_str());    //Nom du fichier ../images/personnage/droite/run_f0.png par exemple
            if(Surface)
            {
                TabAnim[i][j] = SDL_CreateTextureFromSurface(Main_Renderer,Surface);
                if(TabAnim[i][j] == NULL)
                    SDL_Log("Unable to create texture : %s", SDL_GetError());
            }
            else
                SDL_Log("Unable to load image : %s", SDL_GetError());
            
        } 
    }
    hitbox->h = Surface->h;
    hitbox->w = Surface->w;
    pos_x = SPAWN_X;
    pos_y = SPAWN_Y;
    Update_Hitbox();
    this->setSprite_Texture(TabAnim[DROITE][0]);
    SDL_FreeSurface(Surface);
}

Animation::Animation() : AnimFile(""), framerate(0), frame(0), direction_x(DROITE), direction_y(HAUT)
{}

Animation::~Animation()
{
    for(int i = 0; i<2; i++)
        for(int j = 0; j<IPA; j++)
            SDL_DestroyTexture(TabAnim[i][j]);
}

void Animation::Update_Texture()
{
    if(!this->timer.IsRunning())
        this->timer.restart();
    if(this->timer.getTime() >= (1.0/framerate)*1000)
    {
        this->timer.restart();
        frame++;
        if(frame >= IPA || statique) //Soit on loop l'animation soit on est statique
            frame = 0;
    }
    this->setSprite_Texture(TabAnim[direction_x][frame]);
}

void Animation::setDirectionX(int _direction_x)
{
    direction_x = _direction_x;
}

void Animation::setDirectionY(int _direction_y)
{
    direction_y = _direction_y;
}