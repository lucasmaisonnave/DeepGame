#include "deepg.h"



Game::Game(): Window::Window(), Timer::Timer(), Evenement::Evenement()
{}
Game::~Game()
{}
void Game::run()
{
    
    this->setBackground(FILE_BACKGROUND);
    this->RenderBackground();

    Player player(Main_Renderer, FPS_ANIMATION);
    Walls murs(Main_Renderer);
    murs.addWall("../images/frames/wall_mid.png", 200,100);
    
    murs.render();
    player.Update_Player();

    this->update_Window();

    while(!this->quit)
    {
        this->Timer_getTime();    //Restart du Timer
        this->UpdateEvent();
        
        if(this->IsKeyPressed(KEY_DOWN,KEY_RIGHT))
            player.setVitesseX(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_LEFT))
            player.setVitesseX(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_RIGHT))
            player.setVitesseX(0);
        if(this->IsKeyPressed(KEY_UP,KEY_LEFT))
            player.setVitesseX(0);

        if(this->IsKeyPressed(KEY_DOWN,KEY_BACKWARD))
            player.setVitesseY(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_FORWARD))
            player.setVitesseY(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_BACKWARD))
            player.setVitesseY(0);
        if(this->IsKeyPressed(KEY_UP,KEY_FORWARD))
            player.setVitesseY(0);

        this->RenderBackground();                   //On remet le background
        player.Update_Player();  //On actualise la texture du personnage

        murs.render();
        this->update_Window();                       //On affiche les changements à l'écran
        int delta_time = (1.0/FPS)*1000 - this->Timer_getTime();
        //std::cout << delta_time << std::endl;
        if(delta_time > 0)
            SDL_Delay(delta_time);
    }
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

void Load_level(int numero_level)
{
    std::ifstream ifs("../level/level" + std::to_string(numero_level) + ".json" );
    Json::Reader reader;
    Json::Value level;
    reader.parse(ifs, level);
    const Json::Value& joueur = level["Joueur"]; 
    const Json::Value& walls = level["Walls"];
    const Json::Value& sol = level["Sol"];
    const Json::Value& piques = level["Piques"];
    const Json::Value& canon = level["Canon"];
    const Json::Value& fin = level["Fin"];
    
    

    /*std::cout << " x: " << joueur["x"].asInt();
    std::cout << " y: " << joueur["y"].asInt();
    std::cout << std::endl;*/
}