#ifndef ANIMATION_H
#define ANIMATION_H

#include "deepg.h"
#include "Sprite.h"
#include "Timer.h"

enum DIRECTION {DROITE, GAUCHE, HAUT, BAS};

class Animation : public Timer
{
protected:
    Sprite* sprite;
    short unsigned int framerate;   //Vitesse de l'animation en image par sec
    std::string AnimFile;           //Fichier où se trouve les images de l'animation
    std::vector<SDL_Texture*> Textures;
    short unsigned int frame = 0;       //Indice de la frame actuel

    
    SDL_Renderer* Main_Renderer;

public:
    Animation(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, Sprite* _sprite);
    Animation();
    ~Animation();
    /*
        Update la texture du sprite
    */
    bool statique = true;           //Si vrai l'animation reste sur la première image
    void Update_Texture();

};



#endif