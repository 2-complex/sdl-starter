
#include <SDL.h>

int main(int argc, char ** argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow(
        "Events", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 45, 20, 100, 255);

    bool quit = false;
    bool mouseDown = false;
    while ( ! quit )
    {
        SDL_Event event;
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_WINDOWEVENT )
            {
                switch (event.window.event)
                {
                    case SDL_WINDOWEVENT_SHOWN:
                        printf("Window %d shown\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_HIDDEN:
                        printf("Window %d hidden\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_EXPOSED:
                        printf("Window %d exposed\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_MOVED:
                        printf("Window %d moved to %d,%d\n",
                            event.window.windowID, event.window.data1,
                            event.window.data2);
                    break;

                    case SDL_WINDOWEVENT_RESIZED:
                        printf("Window %d resized to %dx%d\n",
                            event.window.windowID, event.window.data1,
                            event.window.data2);
                    break;

                    case SDL_WINDOWEVENT_SIZE_CHANGED:
                        printf("Window %d size changed to %dx%d\n",
                            event.window.windowID,
                            event.window.data1,
                            event.window.data2);
                    break;

                    case SDL_WINDOWEVENT_MINIMIZED:
                        printf("Window %d minimized\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_MAXIMIZED:
                        printf("Window %d maximized\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_RESTORED:
                        printf("Window %d restored\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_ENTER:
                        printf("Mouse entered window %d\n",
                            event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_LEAVE:
                        printf("Mouse left window %d\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_FOCUS_GAINED:
                        printf("Window %d gained keyboard focus\n",
                            event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_FOCUS_LOST:
                        printf("Window %d lost keyboard focus\n",
                                event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_CLOSE:
                        printf("Window %d closed\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_TAKE_FOCUS:
                        printf("Window %d is offered a focus\n", event.window.windowID);
                    break;

                    case SDL_WINDOWEVENT_HIT_TEST:
                        printf("Window %d has a special hit test\n", event.window.windowID);
                    break;

                    default:
                        printf("Window %d got unknown event %d\n",
                            event.window.windowID,
                            event.window.event);
                    break;
                }
            }

            if(event.type == SDL_QUIT)
                quit = true;
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
