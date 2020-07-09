#include "deepg.h"



Game::Game(): Window::Window(), Timer::Timer(), Evenement::Evenement()
{
    this->setBackground(FILE_BACKGROUND);
    Load_level(current_level);
}
Game::~Game()
{}
void Game::run()
{
    this->Update_Image();

    while(!this->quit)
    {
        this->Timer_restart();    //Restart du Timer
        this->Update_Inputs();
        this->Update_Image();
        delta_time = (1.0/FPS)*1000 - this->Timer_getTime();
        //std::cout << delta_time << std::endl;
        if(delta_time > 0)
            SDL_Delay(delta_time);
        if(!player->IsAlive())
            Load_level(current_level);
    }
}


void Game::setBackground(std::string _file_background)
{
    SDL_Surface* Surface = IMG_Load(_file_background.c_str());
    if(Surface)
    {   
        Surface = SDL_ConvertSurfaceFormat(Surface, PIXEL_FORMAT, 0);
        if(Surface)
            
            background = SDL_CreateTextureFromSurface(Main_Renderer, Surface);
        else
            SDL_Log("Unable to convert pixel format : %s", SDL_GetError());
    }
    else
        SDL_Log("Unable to load image : %s", SDL_GetError());
    
}

void Game::RenderBackground()
{
    SDL_RenderCopy(Main_Renderer, background, NULL, NULL);
}

void Game::Load_level(int numero_level)
{
    std::ifstream ifs("../level/level" + std::to_string(numero_level) + ".json" );
    Json::Reader reader;
    Json::Value level;
    reader.parse(ifs, level);
    const Json::Value& joueur_data = level["Joueur"]; 
    const Json::Value& walls_data = level["Walls"];
    const Json::Value& sol_data = level["Sol"];
    const Json::Value& spikes_data = level["Spikes"];
    const Json::Value& canon_data = level["Canon"];
    const Json::Value& fin_datat = level["Fin"];
    /*  
        Pour créer les murs on utilise la syntaxe suivant de le .json:
        x et y sont les positions du premier mur à mettre
        nb_x représente le nombre de murs à ajouter selon x
        nb_y de même pour y
        type est le nom du fichier de texture des murs à ajouter
    */
   /*--------On ajoute les murs--------*/
    murs = new Walls(Main_Renderer, background);
    
    for(int i = 0; i < walls_data.size(); i++)
    {
        int x = walls_data[i]["x"].asInt();
        int y = walls_data[i]["y"].asInt();
        int nb_x = walls_data[i]["nb_x"].asInt();
        int nb_y = walls_data[i]["nb_y"].asInt();
        std::string type = walls_data[i]["type"].asString();

        Sprite* pattern = murs->addWall(FOLDER_FRAME + type, x, y);
        int h = pattern->getSprite_Hitbox()->h;
        int w = pattern->getSprite_Hitbox()->w;
        for(int j = 1; j < nb_x; j++)
            murs->addWall(FOLDER_FRAME + type, x + j*w, y);
        
        for(int k = 1; k < nb_y; k++)
            murs->addWall(FOLDER_FRAME + type, x, y + k*h);
    }
    /*--------ON ajoute le player--------*/
    player = new Player(Main_Renderer, murs, FPS_ANIMATION_PLAYER, joueur_data["x"].asInt(), joueur_data["y"].asInt());
    /*--------On ajoute le sol-------*/
    for(int i = 0; i < sol_data.size(); i++)
    {
        int x = sol_data[i]["x"].asInt();
        int y = sol_data[i]["y"].asInt();
        int nb_h = sol_data[i]["nb_h"].asInt();
        int nb_w = sol_data[i]["nb_w"].asInt();
        std::string type = sol_data[i]["type"].asString();

        Sprite* pattern = new Sprite(FOLDER_FRAME + type, x, y, SOL, Main_Renderer);
        this->addSpriteToBackground(pattern);
        int h = pattern->getSprite_Hitbox()->h;
        int w = pattern->getSprite_Hitbox()->w;
        free(pattern);
        for(int k = 0; k < nb_h; k++)
        {
            for(int j = 0; j < nb_w; j++)
            {
                Sprite* sprite = new Sprite(FOLDER_FRAME + type, x + j*w, y +k*h, SOL, Main_Renderer);
                this->addSpriteToBackground(sprite);
                free(sprite);
            }
        }
    }
    /*--------On ajoutes les spikes--------*/
    spikes = new Spikes(Main_Renderer, player);
    for(int i = 0; i < spikes_data.size(); i++)
    {
        int x = spikes_data[i]["x"].asInt();
        int y = spikes_data[i]["y"].asInt();
        spikes->addSpike(x, y);
    }

    
}

void Game::addSpriteToBackground(Sprite* sprite)
{
    if(sprite->getSprite_Texture())
    {
        if(SDL_UpdateTexture(background, sprite->getSprite_Hitbox(), sprite->getPixels(), sprite->getPitch()) == -1)
            SDL_Log("Update du background : %s", SDL_GetError());
    }
    else
        SDL_Log("Sprite texture est vide");
}

void Game::Update_Image()
{
    this->RenderBackground();                   //On remet le background
    spikes->Update_Spikes();                    //On actualise les textures des sprites
    player->Update_Player();                    //On actualise la texture du personnage
    this->update_Window();                      //On affiche les changements à l'écran
}

void Game::Update_Inputs()
{
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
}