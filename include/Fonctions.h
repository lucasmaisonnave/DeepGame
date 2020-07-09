#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "deepg.h"

SDL_Surface *createSurfaceFromTexture(SDL_Texture *texture);
/*SDL_Surface *copie_surface(SDL_Surface *surface_a_copier);*/

/**
 *  \brief Une structure représentant un cercle avec x,y comme centre et r comme rayon
*/
typedef struct SDL_Circle
{
    int x,y;
    int r;
}SDL_Circle;

/**
 *  \brief Renvoie True si il y a intersection entre le cercle et le rectangle
*/
SDL_bool SDL_IntersectionCircleRect(SDL_Rect* _rect, SDL_Circle* _circle);

/**
 *  \brief Renvoie True si le point est dans le cercle
*/
SDL_bool SDL_PointInCircle(SDL_Point* _point, SDL_Circle* _circle);

#endif