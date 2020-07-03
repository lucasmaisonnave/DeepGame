/*#include "Window.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>*/
#include "deepg.h"


Window::Window() : Main_Window(nullptr), Main_Renderer(nullptr), title("DeepGame")
{
    if(SDL_CreateWindowAndRenderer(1200, 720, 0, &Main_Window, &Main_Renderer) != 0)
        SDL_Log("Unable to initialize Window and Renderer : %s", SDL_GetError());
    if(Main_Window)
		SDL_SetWindowTitle(Main_Window, title.c_str());
}

Window::~Window()
{
    if (Main_Renderer)
	{
		SDL_DestroyRenderer(Main_Renderer);
		Main_Renderer = nullptr;
	}

	if (Main_Window)
	{
		SDL_DestroyWindow(Main_Window);
		Main_Window = nullptr;
	}
}

void Window::update_Window() const
{
    SDL_RenderPresent(Main_Renderer);
}

void Window::RenderCopy_Texture(SDL_Texture* _Texture, SDL_Rect* _src, SDL_Rect* _dest)
{
	if(_Texture)
		SDL_RenderCopy(Main_Renderer, _Texture, _src, _dest);
	else
		std::cout << "Erreur lors du RendeerCopy : Texture vide" << std::endl;
	
}
