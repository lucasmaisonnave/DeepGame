#ifndef SPRITE_H
#define SPRITE_H

#include "deepg.h"

enum STATUT_SPRITE {UNDEFINED, INFRANCHISSABLE, ENNEMIE, JOUEUR, DEPLACABLE, END};

#define SPAWN_X 500 //Coordonnées du spaw des sprite
#define SPAWN_Y 400

class Sprite
{
protected:
    SDL_Texture* Sprite_Texture;
    unsigned short int Statut;
    SDL_Rect* hitbox = new SDL_Rect;
    float pos_x;     //Position mais en float
    float pos_y;  
    
    void setSprite_Hitbox(SDL_Rect* _hitbox);
    void setSprite_Texture(SDL_Texture* _Sprite_Texture);
    void setSprite_Statut(const int _Statut);
public:
    Sprite();
    Sprite(const int _Statut);
    ~Sprite();
    SDL_Rect* getSprite_Hitbox();
    SDL_Texture* getSprite_Texture();
    void printSprite() const;
    void Update_Hitbox();    //Met à jour la position de la hitbox en fonction de pos_x et pos_y
};

#endif