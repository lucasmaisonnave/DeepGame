#include "deepg.h"

Movable_Object::Movable_Object(SDL_Renderer* _Main_Renderer, int _framerate, std::string _AnimFile, const int _Statut) : Animation::Animation(_Main_Renderer, _framerate, _AnimFile, _Statut), vitesse_x(0), vitesse_y(0)
{}

Movable_Object::~Movable_Object()
{}

void Movable_Object::setVitesseX(float _vitesse_x)
{
    vitesse_x = _vitesse_x;
}

void Movable_Object::setVitesseY(float _vitesse_y)
{
    vitesse_y = _vitesse_y;
}

void Movable_Object::Update_Object()
{
    /*Mis à jour de la direction*/
    if(vitesse_x > 0)
        this->setDirectionX(DROITE);
    else if(vitesse_x < 0)
        this->setDirectionX(GAUCHE);

    if(vitesse_y > 0)
        this->setDirectionY(BAS);
    else if(vitesse_y < 0)
        this->setDirectionY(HAUT);

    if(vitesse_y == 0 && vitesse_x == 0)
        this->statique = true;
    else
        this->statique = false;
    
    
    /*Mise à jour de la position*/
    this->pos_x += vitesse_x;
    this->pos_y += vitesse_y;

    this->Update_Texture();
    this->Update_Hitbox();
}

void Movable_Object::printMovable_Object() const
{
    std::cout << "----------- Movable Object -----------" << std::endl;
    this->printSprite();
    std::cout << "VitesseX = " << vitesse_x << " / VitesseY = " << vitesse_y << std::endl;
    std::cout << "DirectionX = " << direction_x << " / DirectionY = " << direction_y << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}