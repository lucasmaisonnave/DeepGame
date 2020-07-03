#include "deepg.h"



Game::Game(): currentNbMovObject(0), Window::Window(), Timer::Timer(), Evenement::Evenement()
{}
Game::~Game()
{}
void Game::run()
{
    
    this->setBackground(FILE_BACKGROUND);
    this->RenderBackground();

    this->addMovableObject(Main_Renderer,FPS_ANIMATION, FILE_PERSONNAGE, JOUEUR); //Ajoute un joueur
    TabMovObject[ind_joueur]->Update_Object();
    this->RenderCopy_Texture(TabMovObject[ind_joueur]->getSprite_Texture(), NULL, TabMovObject[ind_joueur]->getSprite_Hitbox());
    TabMovObject[ind_joueur]->printMovable_Object();
    this->update_Window();



    //SDL_Delay(5000);
    while(!this->quit)
    {
        this->restart();    //Restart du Timer
        this->UpdateEvent();
        
        if(this->IsKeyPressed(KEY_DOWN,KEY_RIGHT))
            TabMovObject[ind_joueur]->setVitesseX(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_LEFT))
            TabMovObject[ind_joueur]->setVitesseX(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_RIGHT))
            TabMovObject[ind_joueur]->setVitesseX(0);
        if(this->IsKeyPressed(KEY_UP,KEY_LEFT))
            TabMovObject[ind_joueur]->setVitesseX(0);

        if(this->IsKeyPressed(KEY_DOWN,KEY_BACKWARD))
            TabMovObject[ind_joueur]->setVitesseY(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_FORWARD))
            TabMovObject[ind_joueur]->setVitesseY(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_BACKWARD))
            TabMovObject[ind_joueur]->setVitesseY(0);
        if(this->IsKeyPressed(KEY_UP,KEY_FORWARD))
            TabMovObject[ind_joueur]->setVitesseY(0);

        this->RenderBackground();                   //On remet le background
        TabMovObject[ind_joueur]->Update_Object();  //On actualise la texture du personnage

        this->RenderCopy_Texture(TabMovObject[ind_joueur]->getSprite_Texture(), NULL, TabMovObject[ind_joueur]->getSprite_Hitbox());
        this->update_Window();                       //On affiche les changements à l'écran
        int delta_time = (1.0/FPS)*1000 - this->getTime();
        //std::cout << delta_time << std::endl;
        if(delta_time > 0)
            SDL_Delay(delta_time);
    }
}

void Game::addMovableObject(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut)
{
    TabMovObject[currentNbMovObject] = new Movable_Object(_Main_Renderer, _framerate,_AnimFile, _Statut);
    if(_Statut == JOUEUR)
        ind_joueur = currentNbMovObject;
    currentNbMovObject++;
}

void Game::setBackground(std::string _file_background)
{
    SDL_Surface* Surface = IMG_Load(_file_background.c_str());
    if(Surface)
        background = SDL_CreateTextureFromSurface(Main_Renderer, Surface);
    else
    {
        SDL_Log("Unable to load image : %s", SDL_GetError());
    }
    
}

void Game::RenderBackground() const
{
    SDL_RenderCopy(Main_Renderer, background, NULL, NULL);
}