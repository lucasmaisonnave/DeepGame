#include "deepg.h"

Sprite::Sprite() :Sprite_Texture(nullptr), Statut(UNDEFINED)
{}
Sprite::Sprite(const int _Statut):  Sprite_Texture(nullptr), Statut(_Statut)
{}

Sprite::Sprite(std::string FileName, int _x, int _y, const int _Statut, SDL_Renderer* _Main_Renderer)
{
    SDL_Surface* Surface = IMG_Load(FileName.c_str());
    if(Surface)
    {
        Sprite_Texture = SDL_CreateTextureFromSurface(_Main_Renderer,Surface);
        if(Sprite_Texture)
        {
            hitbox->w = Surface->w;
            hitbox->h = Surface->h;
            pos_x = _x;
            pos_y = _y;
            Update_Hitbox();
        }
        else
            SDL_Log("Unable to create texture : %s", SDL_GetError());
    }
    else
        SDL_Log("Unable to load image : %s", SDL_GetError());
    
}

Sprite::~Sprite()
{
    hitbox = nullptr; 
    Sprite_Texture = nullptr; 
    Statut = UNDEFINED;
}
void Sprite::setSprite_Hitbox(SDL_Rect* _hitbox)
{
    hitbox = _hitbox;
}
void Sprite::setSprite_Texture(SDL_Texture* _Sprite_Texture)
{
    if(_Sprite_Texture)
        Sprite_Texture = _Sprite_Texture;
    else
        std::cout << "Sprite Texture vide" << std::endl;
}
void Sprite::setSprite_Statut(const int _Statut)
{
    Statut = _Statut;
}

void Sprite::setHitbox_wh(int _w, int _h)
{
    hitbox->h = _h;
    hitbox->w = _w;
}


SDL_Texture* Sprite::getSprite_Texture()
{
    return Sprite_Texture;
}
SDL_Rect* Sprite::getSprite_Hitbox()
{
    return hitbox;
}
void Sprite::printSprite() const
{
    std::cout << "Sprite : " << Statut << std::endl;
    if(hitbox)
        std::cout << "Hitbox : x : " << hitbox->x << " / y : " << hitbox->y << " / h : " << hitbox->h << " / w : " << hitbox->w << std::endl;
    else
        std::cout << "Hitbox : NULL" << std::endl;

    if(Sprite_Texture)
        std::cout << "Texture : Non NULL " << std::endl;
    else
        std::cout << "Texture : NULL " << std::endl;
    
    
}


void Sprite::Update_Hitbox()
{
    hitbox->x = (int)pos_x;
    hitbox->y = (int)pos_y;
}