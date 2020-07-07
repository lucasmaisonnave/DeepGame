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