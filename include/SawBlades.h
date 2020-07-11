#ifndef SAW_BLADES_H
#define SAW_BLADES_H

#include "deepg.h"
#include "Fonctions.h"
#include "Game.h"

#define VITESSE_SAW 120.0   // °/s
#define VITESSE_ROTATION 0.5  // °/s
#define SAW_FILE "../images/frames/saw_blade.jpg"

class Saw : public Sprite
{
protected:
    float Vitesse = 0;    //Norme de la vitesse
    float v_x = 0;  //Pixel par frame
    float v_y = 0;
    
    float vitesse_rotation =  VITESSE_ROTATION;   //En degré par frame
    /*Coéficients de la trajectoire : y = ax+b*/
    float a = 0;
    float b = 0;
    /*Les 2 points caractérisant la trajectoire*/
    SDL_Point* start_point;
    SDL_Point* end_point;

    SDL_Circle* saw_hitbox = new SDL_Circle;  //Hitbox de la scie qui est différente de la hitbox du sprite qui ne sera pas utilisé car c'est un carré

    int max_x;
    int min_x;
    int max_y;
    int min_y;

    /*
        Calcul les coefs de la fonction affine en fonction des 2 points
    */
    void calcul_coef_vitesse();
public:
    Saw(std::string FileName, const int _Statut, SDL_Renderer* _Main_Renderer, SDL_Point* _start_point, SDL_Point* _end_point, float _Vitesse);
    ~Saw();
    /*
        Update à faire toutes les frames
        qui va mettre à jour la position de la scie ainsi
        que la faire tourner
    */
    void Update_Saw();
    /*
        Renvoie true si le rectangle a une intersection avec la scie
    */
    bool Intersection(SDL_Rect* _rect);
};

class SawBlades
{
private:
    std::vector<Saw*> sawblades;
    SDL_Renderer* Main_Renderer = nullptr;
    Player* player;
public:
    SawBlades(SDL_Renderer* _Main_Renderer, Player* _player);
    ~SawBlades();
    void addSaw(std::string FileName, SDL_Point* _start_point, SDL_Point* _end_point, float _Vitesse);
    void Update_SawBlades();

};


#endif