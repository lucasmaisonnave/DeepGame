#include "deepg.h"

Walls::Walls(SDL_Renderer* _Main_Renderer, SDL_Texture* _background) : Main_Renderer(_Main_Renderer), background(_background)
{}
Walls::~Walls()
{}

Sprite* Walls::addWall(std::string FileName, int pos_x, int pos_y)
{

    Sprite* mur = new Sprite(FileName, pos_x, pos_y, WALL, Main_Renderer);
    if(mur)
    {
        this->addWallToBackground(mur);
        walls.push_back(mur);
    }
    return mur;
}

bool Walls::IsInWall(SDL_Rect* _hitbox)
{
    if(_hitbox)
    {
        for(int i = 0; i < walls.size(); i++)
            if(SDL_HasIntersection(_hitbox, walls[i]->getSprite_Hitbox()))
                return true;
        return false;
    }
    else
        std::cout << "Walls : IsInWall(), la hitbox d'entrée est NULL" << std::endl;
    
}

void Walls::render()
{
    for(int i = 0; i < walls.size(); i++)
        SDL_RenderCopy(Main_Renderer, walls[i]->getSprite_Texture(), NULL, walls[i]->getSprite_Hitbox());
}

int Walls::size()
{
    return walls.size();
}

void Walls::addWallToBackground(Sprite* wall)
{
    Uint32 format_pixels_wall, format_pixels_background;
    SDL_Surface *surface = NULL;
    void *pixels = NULL;
    int pitch, w, h;
    SDL_QueryTexture(wall->getSprite_Texture(), &format_pixels_wall, NULL, &w, &h);
    SDL_QueryTexture(background, &format_pixels_background, NULL, &w, &h);
    std::cout << "format_pixels_wall : " << format_pixels_wall << std::endl << "format_pixels_background : " << format_pixels_background << std::endl;

    SDL_LockTexture(wall->getSprite_Texture(), NULL, &pixels, &pitch);

    if(SDL_UpdateTexture(background, wall->getSprite_Hitbox(), pixels, pitch) == -1)
        SDL_Log("Update du background : %s", SDL_GetError());
    SDL_UnlockTexture(wall->getSprite_Texture());
}