#include "deepg.h"

Player::Player(SDL_Renderer* _Main_Renderer,Walls* _murs, int _framerate, int _spawn_x, int _spawn_y) : Main_Renderer(_Main_Renderer), murs(_murs), Sprite::Sprite(JOUEUR), spawn_x(_spawn_x), spawn_y(_spawn_y)
{
    Anim_Run = new Animation(Main_Renderer, _framerate, PLAYER_FILE, this, false);
    Anim_Run->Update_Texture();  //On initialise le joueur avec la texture de droite
    this->pos_x = spawn_x;
    this->pos_y = spawn_y;
    this->Update_Hitbox();
}

Player::~Player()
{}

void Player::setVitesseX(float _vitesse_x)
{
    vitesse_x = _vitesse_x;
}
void Player::setVitesseY(float _vitesse_y)
{
    vitesse_y = _vitesse_y;
}

void Player::setDirectionX(float _direction_x)
{
    direction_x = _direction_x;
}
void Player::setDirectionY(float _direction_y)
{
    direction_y = _direction_y;
}

void Player::Update_Player()
{
     if(vitesse_x > 0)
        this->setDirectionX(DROITE);
    else if(vitesse_x < 0)
        this->setDirectionX(GAUCHE);

    if(vitesse_y > 0)
        this->setDirectionY(BAS);
    else if(vitesse_y < 0)
        this->setDirectionY(HAUT);

    if(vitesse_y == 0 && vitesse_x == 0)
        Anim_Run->statique = true;
    else
        Anim_Run->statique = false;
    
    
    /*Mise à jour de la position*/
    this->pos_x += vitesse_x;
    this->pos_y += vitesse_y;
    this->Update_Hitbox();

    if(murs->IsInWall(this->getSprite_Hitbox()))
    {
        if(vitesse_x != 0)
            this->pos_x -= vitesse_x;
        if(vitesse_y != 0)
            this->pos_y -= vitesse_y;
        this->Update_Hitbox();
    }

    if(direction_x == DROITE)
    {
        Anim_Run->Update_Texture();
        flip = SDL_FLIP_NONE;
    }
        
    else
    {
        Anim_Run->Update_Texture();
        flip = SDL_FLIP_VERTICAL;
    }
    this->render();
}


void Player::render()
{
    if(flip == SDL_FLIP_NONE)
        SDL_RenderCopyEx(Main_Renderer, this->getSprite_Texture(), NULL, this->getSprite_Hitbox(),0, NULL, flip);
    else
        SDL_RenderCopyEx(Main_Renderer, this->getSprite_Texture(), NULL, this->getSprite_Hitbox(),180, NULL, flip);
}

void Player::die()
{
    alive = false;
}

bool Player::IsAlive() const
{
    return alive;
}
