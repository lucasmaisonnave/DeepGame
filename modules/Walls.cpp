#include "deepg.h"

Walls::Walls(SDL_Renderer* _Main_Renderer) : Main_Renderer(_Main_Renderer)
{}
Walls::~Walls()
{}

int Walls::addWall(std::string FileName, int pos_x, int pos_y)
{

    Sprite* mur = new Sprite(FileName, pos_x, pos_y, WALL, Main_Renderer);
    if(mur)
    {
        walls.push_back(mur);
        return 1;
    }
    return -1;
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