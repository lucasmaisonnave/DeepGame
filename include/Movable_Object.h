#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "deepg.h"

class Movable_Object : public Animation
{
private:
    float vitesse_x;
    float vitesse_y;
public:
    Movable_Object(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut);
    ~Movable_Object();
    void setVitesseX(float _vitesse_x);
    void setVitesseY(float _vitesse_y);
    /*
        Actualise l'objet mobile en fonction de sa vitesse
        et actualise le renderer
    */
    void Update_Object();

    void printMovable_Object() const;

};

#endif