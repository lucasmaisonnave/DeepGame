#ifndef ANIMATION_H
#define ANIMATION_H

#include "deepg.h"
#include "Sprite.h"
#include "Timer.h"
#define IPA 4 //Images par animation

enum DIRECTION {DROITE, GAUCHE, HAUT, BAS};

class Animation: public Sprite
{
protected:
    short unsigned int framerate;   //Vitesse de l'animation en image par sec
    bool statique = true;
    std::string AnimFile;           //Fichier où se trouve les images de l'animation
    SDL_Texture* TabAnim[2][IPA];   //Tableau contenant les textures des animations de course droite et gauche
    Timer timer;
    short unsigned int frame;       //Indice de la frame actuel
    short unsigned int direction_x;   //Indice de la direction
    short unsigned int direction_y;

    void setDirectionX(int _direction_x);
    void setDirectionY(int _direction_y);

    SDL_Renderer* Main_Renderer;

public:
    Animation(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut);
    Animation();
    ~Animation();
    /*
        Update la texture du sprite
    */
    void Update_Texture();
    

};



#endif