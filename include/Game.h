#ifndef GAME_H
#define GAME_H

#include "deepg.h"
#include "Player.h"
#include "Walls.h"
#include "Spikes.h"

#define FPS 60              //Images par seconde du jeu
#define FPS_ANIMATION_PLAYER 12     //Vitesse d'affichage des images des animations
#define FPS_ANIMATION_SPIKE 1
#define FILE_PERSONNAGE "../images/personnage"
#define FILE_BACKGROUND "../images/background.png"
#define FOLDER_FRAME "../images/frames/"

#define VITESSE_PERSONNAGE 80.0   //Pixel par seconde

#define PIXEL_FORMAT SDL_PIXELFORMAT_ABGR8888

class Game : public Evenement, public Timer, public Window
{
private:
    SDL_Texture* background;
    Player* player;
    Walls* murs;
    Spikes* spikes;
    /*
        Ajoute la texture du sprite au background
        de façon permanente
    */
    void addSpriteToBackground(Sprite* sprite);
public:
    Game();
    ~Game();
    void run();
    void setBackground(std::string _file_backgroun);
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