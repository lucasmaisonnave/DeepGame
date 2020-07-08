#ifndef SPIKES_H
#define SPIKES_H

#include "deepg.h"

#define SPIKE_FILE "../images/frames/floor_spikes_anim_f"

class Spikes
{
private:
    std::vector<Animation*> spikes;   //Tableau contenant tous les spikes
    SDL_Renderer* Main_Renderer = nullptr;
    void render();
public:
    Spikes(SDL_Renderer* _Main_Renderer);
    ~Spikes();
    /*
        Ajoute un spike aux coordonnées
        spécifiées
    */
    void addSpike(int _x, int _y);
    /*
        Copie toutes les textures des spikes ajoutés
        dans le Main Renderer
    */
    void Update_Spikes();
};

#endif