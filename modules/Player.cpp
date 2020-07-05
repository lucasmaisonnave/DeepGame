#include "deepg.h"

Player::Player(SDL_Renderer* _Main_Renderer, int _framerate) : Main_Renderer(_Main_Renderer), Sprite::Sprite(JOUEUR)
{
    Anim_Droite = new Animation(Main_Renderer, _framerate, "../images/personnage/droite/run_f", this);
    Anim_Gauche = new Animation(Main_Renderer, _framerate, "../images/personnage/gauche/run_f", this);
    Anim_Droite->Update_Texture();  //On initialise le joueur avec la texture de droite
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
    {
        Anim_Droite->statique = true;
        Anim_Gauche->statique = true;
    }
    else
    {
        Anim_Droite->statique = false;
        Anim_Gauche->statique = false;
    }
    
    
    /*Mise à jour de la position*/
    this->pos_x += vitesse_x;
    this->pos_y += vitesse_y;

    if(direction_x == DROITE)
        Anim_Droite->Update_Texture();
    else
        Anim_Gauche->Update_Texture();
    
    
    this->Update_Hitbox();
    this->render();
}


void Player::render()
{
    SDL_RenderCopy(Main_Renderer, this->getSprite_Texture(), NULL, this->getSprite_Hitbox());
}