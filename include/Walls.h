#ifndef WALLS_H
#define WALLS_H

#include "deepg.h"
#include "Sprite.h"


class Walls
{
private:
    std::vector<Sprite*> walls;   //Tableau contenant tous les murs
    SDL_Renderer* Main_Renderer = nullptr;
    SDL_Texture* background;
    /*
        Ajoute la texture de mur sur le background
    */
    void addWallToBackground(Sprite* wall);
public:
    Walls(SDL_Renderer* _Main_Renderer, SDL_Texture* _background);
    ~Walls();
    /*
        Ajoute un mur à la position spécifié avec la
        texture du FileName
        retourne -1 s'il y a une erreur
    */
    Sprite* addWall(std::string FileName, int pos_x, int pos_y);
    /*
        Retourne true si le point est dans un mur
    */
    bool IsInWall(SDL_Rect* _hitbox);
    /*
        Retourne le nombre de mur dans walls
    */
    int size();

    void render();

};

#endif