#ifndef PLAYER_H
#define PLAYER_H

#include "deepg.h"
#include "Walls.h"

class Player : public Sprite
{
private:
    float vitesse_x = 0;
    float vitesse_y = 0;

    const int spawn_x ;
    const int spawn_y ;

    int direction_x = DROITE;
    int direction_y = HAUT;

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    Animation* Anim_Run;
    SDL_Renderer* Main_Renderer;

    Walls* murs;    //Tous les murs de la map

    void render();
public:
    Player(SDL_Renderer* _Main_Renderer, Walls* _murs, int _framerate, int _spawn_x = SPAWN_X, int _spawn_y = SPAWN_Y);
    ~Player();

    void setVitesseX(float _vitesse_x);
    void setVitesseY(float _vitesse_y);

    void setDirectionX(float _direction_x);
    void setDirectionY(float _direction_y);

    void Update_Player();

};


#endif
