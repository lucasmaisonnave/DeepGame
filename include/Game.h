#ifndef GAME_H
#define GAME_H

#include "deepg.h"
#include "Player.h"

#define FPS 60              //Images par seconde du jeu
#define FPS_ANIMATION 12     //Vitesse d'affichage des images des animations

#define FILE_PERSONNAGE "../images/personnage"
#define FILE_BACKGROUND "../images/background.png"

#define VITESSE_PERSONNAGE 80   //Pixel par seconde

class Game : public Evenement, public Timer, public Window
{
private:
    SDL_Texture* background;
public:
    Game();
    ~Game();
    void run();
    void setBackground(std::string _file_background);
    /*
        Remet le Background
    */
    void RenderBackground() const ;
    /*
        Configure le niveau du numéro correspondant 
        dans le jeu
    */
    void Load_level(int numero_level);

};

#endif