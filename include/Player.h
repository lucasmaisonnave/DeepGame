#ifndef PLAYER_H
#define PLAYER_H

#include "deepg.h"

class Player : public Sprite
{
private:
    float vitesse_x = 0;
    float vitesse_y = 0;

    const int spawn_x = SPAWN_X;
    const int spawn_y = SPAWN_Y;

    int direction_x = DROITE;
    int direction_y = HAUT;

    Animation* Anim_Droite;
    Animation* Anim_Gauche;
    SDL_Renderer* Main_Renderer;

    void render();
public:
    Player(SDL_Renderer* _Main_Renderer, int _framerate);
    ~Player();

    void setVitesseX(float _vitesse_x);
    void setVitesseY(float _vitesse_y);

    void setDirectionX(float _direction_x);
    void setDirectionY(float _direction_y);

    void Update_Player();

};


#endif
