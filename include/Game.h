#ifndef GAME_H
#define GAME_H

#include "deepg.h"
#include "Movable_Object.h"

#define NbMovObject 10   //Nombre d'animations max

#define FPS 60              //Images par seconde du jeu
#define FPS_ANIMATION 12     //Vitesse d'affichage des images des animations

#define FILE_PERSONNAGE "../images/personnage"
#define FILE_BACKGROUND "../images/background.png"

#define VITESSE_PERSONNAGE 300.0   //Pixel par seconde

class Game : public Evenement, public Timer, public Window
{
private:
    Movable_Object* TabMovObject[NbMovObject];
    unsigned int currentNbMovObject; //Nombre d'objet en mouvement dans le tableau
    SDL_Texture* background;
public:
    Game();
    ~Game();
    void run();
    void addMovableObject(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut);
    void setBackground(std::string _file_background);
    /*
        Remet le Background
    */
    void RenderBackground() const ;

    short unsigned int ind_joueur;   //Indice du jour dans TabAnim
};

#endif