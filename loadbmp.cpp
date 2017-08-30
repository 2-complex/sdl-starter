#include "SDL.h"
#include "stdio.h"

int main ( int argc, char *argv[] )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow(
        "Load BMP", 100, 100, 640, 480, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = SDL_LoadBMP("sdl_logo.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_Event event;
    bool quitting = 0;

    while( ! quitting )
    {
        if( SDL_PollEvent(&event) )
        {
            switch( event.type )
            {
                case SDL_QUIT:
                    quitting = true;
                    break;

                case SDL_KEYDOWN:
                    if( event.key.keysym.sym == SDLK_ESCAPE ||
                        event.key.keysym.sym == SDLK_q )
                    {
                        quitting = true;
                    }
                break;
            }
        }

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_FreeSurface(image);
    SDL_Quit();

    return 0;
}

