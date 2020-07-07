#ifndef WINDOW_H
#define WINDOW_H
#include "deepg.h"

#define WIN_WIDTH 1200
#define WIN_HEIGHT 720

class Window
{
protected:
    SDL_Window* Main_Window;
    std::string title;
public:
    Window();
    virtual ~Window();
    /*
        Affiche le renderer
    */
    void update_Window() const;
    /*
        Copie la texture dans le renderer
    */
    void RenderCopy_Texture(SDL_Texture* _Texture, SDL_Rect* _src, SDL_Rect* _dest);

    SDL_Renderer* Main_Renderer;
};



#endif
