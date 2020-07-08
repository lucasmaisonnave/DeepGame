#include "deepg.h"

Spikes::Spikes(SDL_Renderer* _Main_Renderer) : Main_Renderer(_Main_Renderer)
{}
Spikes::~Spikes()
{}

void Spikes::addSpike(int _x, int _y)
{
    std::string nb = "0.png";
    Sprite* spike = new Sprite(SPIKE_FILE + nb, _x, _y, ENNEMIE, Main_Renderer);
    Animation* Anim_Spike = new Animation(Main_Renderer, FPS_ANIMATION_SPIKE, SPIKE_FILE, spike);
    if(Anim_Spike)
    {
        Anim_Spike->statique = false;
        spikes.push_back(Anim_Spike);
    }
        
    else
        std::cout << "FONCTION addSpike : Unable to create a spike" << std::endl;
}

void Spikes::Update_Spikes()
{
    for(int i = 0; i < spikes.size(); i++)
    {
        spikes[i]->Update_Texture();
        SDL_RenderCopy(Main_Renderer, spikes[i]->getCurrent_Texture(), NULL, spikes[i]->getCurrent_Hitbox());
    }
}