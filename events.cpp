
#include <SDL.h>

int main(int argc, char ** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow(
        "Events", 100, 100, 640, 480, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 45, 20, 100, 255);

    bool quit = false;
    bool mouseDown = false;
    while ( ! quit )
    {
        SDL_Event event;
        while( SDL_PollEvent( &event ) )
        {
            switch ( event.type )
            {
                case SDL_KEYDOWN:
                    switch( event.key.keysym.sym )
                    {
                        case SDLK_UP:
                            printf("up\n");
                        break;

                        case SDLK_DOWN:
                            printf("down\n");
                        break;

                        case SDLK_LEFT:
                            printf("left\n");
                        break;

                        case SDLK_RIGHT:
                            printf("right\n");
                        break;
                    }
                break;

                case SDL_KEYUP:
                break;

                case SDL_TEXTEDITING:
                break;

                case SDL_TEXTINPUT:
                break;

                case SDL_MOUSEMOTION:
                    {
                        if( mouseDown )
                        {
                            int mouseX = event.motion.x;
                            int mouseY = event.motion.y;

                            printf( "mouse-dragged %d Y: %d\n", mouseX, mouseY );
                        }
                    }
                break;

                case SDL_MOUSEBUTTONDOWN:
                    {
                        mouseDown = true;

                        int mouseX = event.motion.x;
                        int mouseY = event.motion.y;

                        printf( "mouse-down %d Y: %d\n", mouseX, mouseY );
                    }
                break;

                case SDL_MOUSEBUTTONUP:
                    {
                        mouseDown = false;

                        int mouseX = event.motion.x;
                        int mouseY = event.motion.y;

                        printf( "mouse-up %d Y: %d\n", mouseX, mouseY );
                    }
                break;

                case SDL_MOUSEWHEEL:
                break;

                case SDL_QUIT:
                    quit = true;
                break;
            }
        }

        SDL_Delay(1);

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
