#include "deepg.h"



Saw::Saw(std::string FileName, const int _Statut, SDL_Renderer* _Main_Renderer, SDL_Point* _start_point, SDL_Point* _end_point, float _Vitesse) : 
start_point(_start_point), end_point(_end_point), Vitesse(_Vitesse),
Sprite::Sprite(FileName, _start_point->x , _start_point->y , _Statut, _Main_Renderer)
{
    this->pos_x -= this->hitbox->w/2;
    this->pos_y -= this->hitbox->h/2;
    this->Update_Hitbox();

    this->calcul_coef_vitesse();
    saw_hitbox->x = start_point->x;
    saw_hitbox->y = start_point->y;
    
    if(this->getSprite_Hitbox())
        saw_hitbox->r = this->getSprite_Hitbox()->w/2;
    else
        std::cout << "Saw : sprite hitbox vide" << std::endl;

    max_x = start_point->x > end_point->x ? start_point->x : end_point->x;
    min_x = start_point->x < end_point->x ? start_point->x : end_point->x;
    max_y = start_point->y > end_point->y ? start_point->y : end_point->y;
    min_y = start_point->y < end_point->y ? start_point->y : end_point->y;
    
}
Saw::~Saw()
{

}

void Saw::calcul_coef_vitesse()
{
    float x1 = start_point->x;
    float y1 = start_point->y;
    float x2 = end_point->x;
    float y2 = end_point->y;

    if(x1 == x2)    //Droite verticale
    {
        v_x = 0;
        v_y = Vitesse;
    }
    else if(y1 == y2)    //Droite horizontale
    {
        v_x = Vitesse;
        v_y = 0;
    }
    else                //Courbe affine
    {
        a = (y2-y1)/(x2-x1);
        b = y1 - a*x1;
        v_x = -sign(x1-x2)*Vitesse/(std::sqrt(std::pow(a,2)+1)); //v_x = V/sqrt(a^2+1)
        v_y = a*v_x;
    }
    /*if(a != 0 && b != 0)
    {
        float delta = -4*(std::pow(b,2) - (std::pow(Vitesse,2))*(std::pow(a,2) + 1));
        if(delta >= 0)
        {
            v_x = (-2*a*b + 2*std::sqrt(delta))/(2*(std::pow(a,2)+1));
            v_y = a*v_x + b;
        }
        std::cout << delta << std::endl;
        
    }
    */

}
void Saw::Update_Saw()
{
    
    this->pos_x += v_x;
    this->pos_y += v_y;

    //std::cout << min_x << " < " << this->pos_x + this->hitbox->w/2 << " < " << max_x << std::endl;

    if(!(min_x <= this->pos_x + this->hitbox->w/2 && 
        this->pos_x + this->hitbox->w/2 <= max_x && 
        min_y <= this->pos_y + this->hitbox->h/2 && 
        this->pos_y + this->hitbox->h/2 <= max_y))
    {
        this->pos_x -= v_x;
        this->pos_y -= v_y;

        v_x = -v_x;
        v_y = -v_y;
    }
    this->Update_Hitbox();
    saw_hitbox->x = this->hitbox->x + this->hitbox->w/2;
    saw_hitbox->y = this->hitbox->y + this->hitbox->h/2;
    angle += vitesse_rotation;
    if(angle >= 180)
        angle -= 180;
    if(SDL_RenderCopyEx(Main_Renderer, this->getSprite_Texture(), NULL, this->getSprite_Hitbox(), angle, NULL, SDL_FLIP_NONE) == -1)
        SDL_Log("Unable to update Saw : %s", SDL_GetError());
}

bool Saw::Intersection(SDL_Rect* _rect)
{
    return SDL_IntersectionCircleRect(_rect, saw_hitbox);
}





SawBlades::SawBlades(SDL_Renderer* _Main_Renderer, Player* _player) : Main_Renderer(_Main_Renderer)
{
    if(_player)
        player = _player;
    else
        std::cout << "Constructeur Spike : player NULL" << std::endl;
}
SawBlades::~SawBlades()
{

}
void SawBlades::addSaw(std::string FileName, SDL_Point* _start_point, SDL_Point* _end_point, float _Vitesse)
{
    Saw* saw = new Saw(FileName, ENNEMIE, Main_Renderer, _start_point, _end_point, _Vitesse);
    if(saw)
    {
        sawblades.push_back(saw);
    }
    else
        std::cout << "FONCTION addSaw : Unable to create a saw" << std::endl;
}
void SawBlades::Update_SawBlades()
{
    for(int i = 0; i < sawblades.size(); i++)
    {
        sawblades[i]->Update_Saw();
        if(sawblades[i]->Intersection(player->getSprite_Hitbox()))
            player->die();
    }
}