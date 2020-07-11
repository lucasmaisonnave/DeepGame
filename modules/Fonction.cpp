#include "deepg.h"

SDL_Surface *createSurfaceFromTexture(SDL_Texture *texture)
{
    Uint32 format_pixels;
    SDL_Surface *surface = NULL;
    void *pixels = NULL;
    int pitch, w, h;

    if (SDL_QueryTexture(texture, &format_pixels, NULL, &w, &h) != 0)
    {
        fprintf(stderr, "SDL_QueryTexture: %s.\n", SDL_GetError());
        goto query_texture_fail;
    }

    if (SDL_LockTexture(texture, NULL, &pixels, &pitch) != 0)
    {
        fprintf(stderr, "SDL_LockTexture: %s.\n", SDL_GetError());
        goto lock_texture_fail;
    }

    surface = SDL_CreateRGBSurfaceWithFormatFrom(pixels, w, h, 32, w * sizeof(Uint32), format_pixels);
    if(NULL == surface)
        fprintf(stderr, "Erreur SDL_CreateSurfaceFrom : %s.\n", SDL_GetError());

    SDL_UnlockTexture(texture);
lock_texture_fail:
query_texture_fail:
    return surface;
}

/*SDL_Surface *copie_surface(SDL_Surface *surface_a_copier)
{
    SDL_Surface *surface_copiee = NULL;
    surface_copiee = SDL_CreateRGBSurface(SDL_HWSURFACE, surface_a_copier->w, surface_a_copier->h, surface_a_copier->format->BitsPerPixel, surface_a_copier->format->Rmask, surface_a_copier->format->Gmask, surface_a_copier->format->Bmask, surface_a_copier->format->Amask);
 
    if(surface_copiee == NULL || surface_a_copier == NULL)
        return NULL;
 
    SDL_FreeSurface(surface_copiee);   // pour libérer la surface
    surface_copiee = NULL;
 
    return SDL_DisplayFormatAlpha(surface_a_copier);
}*/

bool SDL_IntersectionCircleRect(SDL_Rect* _rect, SDL_Circle* _circle)
{
    float x = _rect->x;
    float y = _rect->y;
    float w = _rect->w;
    float h = _rect->h;

    float a = _circle->x;
    float b = _circle->y;
    float r = _circle->r;

    for(int i = 0; i<2; i++)
    {
        if(std::pow(r,2) - std::pow(x + i*w - a,2) >= 0)
        {
            if(y <= b + std::sqrt((std::pow(r,2) - std::pow(x + i*w - a,2))) && (b + std::sqrt((std::pow(r,2) - std::pow(x + i*w - a,2)))) <= y + h)
                return true;
            if(y <= b - std::sqrt((std::pow(r,2) - std::pow(x + i*w - a,2))) && b - std::sqrt((std::pow(r,2) - std::pow(x + i*w - a,2))) <= y + h)
                return true;
        }
    }

    for(int i = 0; i<2; i++)
    {
        if(std::pow(r,2) - std::pow(y + i*h - b,2) >= 0)
        {
            if(x <= a + std::sqrt((std::pow(r,2) - std::pow(y + i*h - b,2))) && a + std::sqrt((std::pow(r,2) - std::pow(y + i*h - b,2))) <= x + w)
                return true;
            if(x <= a - std::sqrt((std::pow(r,2) - std::pow(y + i*h - b,2))) && a - std::sqrt((std::pow(r,2) - std::pow(y + i*h - b,2))) <= x + w)
                return true;
        }
    }    
    return false;
}

bool SDL_PointInCircle(SDL_Point* _point, SDL_Circle* _circle)
{
    return (std::pow(_point->x - _circle->x,2) + std::pow(_point->y - _circle->y,2) <= std::pow(_circle->r,2));
}

int sign(float x)
{
    if( x <= 0)
        return -1;
    return 1;
}