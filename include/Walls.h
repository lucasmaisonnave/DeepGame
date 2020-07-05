#ifndef WALLS_H
#define WALLS_H

#include "deepg.h"
#include "Sprite.h"


class Walls
{
private:
    std::vector<Sprite*> walls;   //Tableau contenant tous les murs
    SDL_Renderer* Main_Renderer = nullptr;
public:
    Walls(SDL_Renderer* _Main_Renderer);
    ~Walls();
    /*
        Ajoute un mur à la position spécifié avec la
        texture du FileName
        retourne -1 s'il y a une erreur
    */
    int addWall(std::string FileName, int pos_x, int pos_y);
    /*
        Retourne true si le point est dans un mur
    */
    bool IsInWall(SDL_Rect* _hitbox);

    void render();

};

#endif