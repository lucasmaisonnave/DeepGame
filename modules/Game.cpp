#include "deepg.h"



Game::Game(): Window::Window(), Timer::Timer(), Evenement::Evenement()
{
    this->setBackground(FILE_BACKGROUND);
    Load_level(1);
}
Game::~Game()
{}
void Game::run()
{
    this->RenderBackground();
    
    
    //murs->render();
    player->Update_Player();

    this->update_Window();

    while(!this->quit)
    {
        this->Timer_getTime();    //Restart du Timer
        this->UpdateEvent();
        
        if(this->IsKeyPressed(KEY_DOWN,KEY_RIGHT))
            player->setVitesseX(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_LEFT))
            player->setVitesseX(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_RIGHT))
            player->setVitesseX(0);
        if(this->IsKeyPressed(KEY_UP,KEY_LEFT))
            player->setVitesseX(0);

        if(this->IsKeyPressed(KEY_DOWN,KEY_BACKWARD))
            player->setVitesseY(VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_DOWN,KEY_FORWARD))
            player->setVitesseY(-VITESSE_PERSONNAGE/FPS);
        if(this->IsKeyPressed(KEY_UP,KEY_BACKWARD))
            player->setVitesseY(0);
        if(this->IsKeyPressed(KEY_UP,KEY_FORWARD))
            player->setVitesseY(0);

        this->RenderBackground();                   //On remet le background
        player->Update_Player();  //On actualise la texture du personnage

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

void Game::Load_level(int numero_level)
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
    /*  
        Pour créer les murs on utilise la syntaxe suivant de le .json:
        x et y sont les positions du premier mur à mettre
        nb_x représente le nombre de murs à ajouter selon x
        nb_y de même pour y
        type est le nom du fichier de texture des murs à ajouter
    */
    murs = new Walls(Main_Renderer, background);
    
    for(int i = 0; i < walls.size(); i++)
    {
        int x = walls[i]["x"].asInt();
        int y = walls[i]["y"].asInt();
        int nb_x = walls[i]["nb_x"].asInt();
        int nb_y = walls[i]["nb_y"].asInt();
        std::string type = walls[i]["type"].asString();

        Sprite* pattern = murs->addWall(FOLDER_WALLS + type, x, y);
        int h = pattern->getSprite_Hitbox()->h;
        int w = pattern->getSprite_Hitbox()->w;
        for(int j = 1; j < nb_x; j++)
            murs->addWall(FOLDER_WALLS + type, x + j*w, y);
        
        for(int k = 1; k < nb_y; k++)
            murs->addWall(FOLDER_WALLS + type, x, y + k*h);
    }
    /*Ici on créer le background contenant le fond de base plus les murs*/
    
    
    player = new Player(Main_Renderer, murs, FPS_ANIMATION, joueur["x"].asInt(), joueur["y"].asInt());
    

}