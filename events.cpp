
#include <SDL.h>

#include <map>
#include <string>

std::string getKeyCodeName(SDL_Keycode key);


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
                    printf( "keydown: %s\n", getKeyCodeName(event.key.keysym.sym).c_str() );
                break;

                case SDL_KEYUP:
                    printf( "keyup:   %s\n", getKeyCodeName(event.key.keysym.sym).c_str() );
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


std::string getKeyCodeName(SDL_Keycode key)
{
    static std::map<SDL_Keycode, std::string> keyMap;
    if( keyMap.empty() )
    {
        struct KeycodeNamePair
        {
            SDL_Keycode key;
            const char* name;
        } pairs[] = {
            {'a', "a"},
            {'b', "b"},
            {'c', "c"},
            {'d', "d"},
            {'e', "e"},
            {'f', "f"},
            {'g', "g"},
            {'h', "h"},
            {'i', "i"},
            {'j', "j"},
            {'k', "k"},
            {'l', "l"},
            {'m', "m"},
            {'n', "n"},
            {'o', "o"},
            {'p', "p"},
            {'q', "q"},
            {'r', "r"},
            {'s', "s"},
            {'t', "t"},
            {'u', "u"},
            {'v', "v"},
            {'w', "w"},
            {'x', "x"},
            {'y', "y"},
            {'z', "z"},
            {'1', "1"},
            {'2', "2"},
            {'3', "3"},
            {'4', "4"},
            {'5', "5"},
            {'6', "6"},
            {'7', "7"},
            {'8', "8"},
            {'9', "9"},
            {'0', "0"},
            {SDLK_RETURN, "SDLK_RETURN"},
            {SDLK_ESCAPE, "SDLK_ESCAPE"},
            {SDLK_BACKSPACE, "SDLK_BACKSPACE"},
            {SDLK_TAB, "SDLK_TAB"},
            {SDLK_SPACE, "SDLK_SPACE"},
            {'-', "-"},
            {'=', "="},
            {'[', "["},
            {']', "]"},
            {'\\', "\\"},
            {'#', "#"},
            {';', ";"},
            {'\'', "\'"},
            {'`', "`"},
            {',', ","},
            {'.', "."},
            {'/', "/"},
            {SDLK_CAPSLOCK, "SDLK_CAPSLOCK"},
            {SDLK_F1, "SDLK_F1"},
            {SDLK_F2, "SDLK_F2"},
            {SDLK_F3, "SDLK_F3"},
            {SDLK_F4, "SDLK_F4"},
            {SDLK_F5, "SDLK_F5"},
            {SDLK_F6, "SDLK_F6"},
            {SDLK_F7, "SDLK_F7"},
            {SDLK_F8, "SDLK_F8"},
            {SDLK_F9, "SDLK_F9"},
            {SDLK_F10, "SDLK_F10"},
            {SDLK_F11, "SDLK_F11"},
            {SDLK_F12, "SDLK_F12"},
            {SDLK_PRINTSCREEN, "SDLK_PRINTSCREEN"},
            {SDLK_SCROLLLOCK, "SDLK_SCROLLLOCK"},
            {SDLK_PAUSE, "SDLK_PAUSE"},
            {SDLK_INSERT, "SDLK_INSERT"},
            {SDLK_HOME, "SDLK_HOME"},
            {SDLK_PAGEUP, "SDLK_PAGEUP"},
            {SDLK_DELETE, "SDLK_DELETE"},
            {SDLK_END, "SDLK_END"},
            {SDLK_PAGEDOWN, "SDLK_PAGEDOWN"},
            {SDLK_RIGHT, "SDLK_RIGHT"},
            {SDLK_LEFT, "SDLK_LEFT"},
            {SDLK_DOWN, "SDLK_DOWN"},
            {SDLK_UP, "SDLK_UP"},
            {SDLK_NUMLOCKCLEAR, "SDLK_NUMLOCKCLEAR"},
            {SDLK_KP_DIVIDE, "SDLK_KP_DIVIDE"},
            {SDLK_KP_MULTIPLY, "SDLK_KP_MULTIPLY"},
            {SDLK_KP_MINUS, "SDLK_KP_MINUS"},
            {SDLK_KP_PLUS, "SDLK_KP_PLUS"},
            {SDLK_KP_ENTER, "SDLK_KP_ENTER"},
            {SDLK_KP_1, "SDLK_KP_1"},
            {SDLK_KP_2, "SDLK_KP_2"},
            {SDLK_KP_3, "SDLK_KP_3"},
            {SDLK_KP_4, "SDLK_KP_4"},
            {SDLK_KP_5, "SDLK_KP_5"},
            {SDLK_KP_6, "SDLK_KP_6"},
            {SDLK_KP_7, "SDLK_KP_7"},
            {SDLK_KP_8, "SDLK_KP_8"},
            {SDLK_KP_9, "SDLK_KP_9"},
            {SDLK_KP_0, "SDLK_KP_0"},
            {SDLK_KP_PERIOD, "SDLK_KP_PERIOD"},
            {SDLK_APPLICATION, "SDLK_APPLICATION"},
            {SDLK_POWER, "SDLK_POWER"},
            {SDLK_KP_EQUALS, "SDLK_KP_EQUALS"},
            {SDLK_F13, "SDLK_F13"},
            {SDLK_F14, "SDLK_F14"},
            {SDLK_F15, "SDLK_F15"},
            {SDLK_F16, "SDLK_F16"},
            {SDLK_F17, "SDLK_F17"},
            {SDLK_F18, "SDLK_F18"},
            {SDLK_F19, "SDLK_F19"},
            {SDLK_F20, "SDLK_F20"},
            {SDLK_F21, "SDLK_F21"},
            {SDLK_F22, "SDLK_F22"},
            {SDLK_F23, "SDLK_F23"},
            {SDLK_F24, "SDLK_F24"},
            {SDLK_EXECUTE, "SDLK_EXECUTE"},
            {SDLK_HELP, "SDLK_HELP"},
            {SDLK_MENU, "SDLK_MENU"},
            {SDLK_SELECT, "SDLK_SELECT"},
            {SDLK_STOP, "SDLK_STOP"},
            {SDLK_AGAIN, "SDLK_AGAIN"},
            {SDLK_UNDO, "SDLK_UNDO"},
            {SDLK_CUT, "SDLK_CUT"},
            {SDLK_COPY, "SDLK_COPY"},
            {SDLK_PASTE, "SDLK_PASTE"},
            {SDLK_FIND, "SDLK_FIND"},
            {SDLK_MUTE, "SDLK_MUTE"},
            {SDLK_VOLUMEUP, "SDLK_VOLUMEUP"},
            {SDLK_VOLUMEDOWN, "SDLK_VOLUMEDOWN"},
            {SDLK_KP_COMMA, "SDLK_KP_COMMA"},
            {SDLK_KP_EQUALSAS400, "SDLK_KP_EQUALSAS400"},
            {SDLK_ALTERASE, "SDLK_ALTERASE"},
            {SDLK_SYSREQ, "SDLK_SYSREQ"},
            {SDLK_CANCEL, "SDLK_CANCEL"},
            {SDLK_CLEAR, "SDLK_CLEAR"},
            {SDLK_PRIOR, "SDLK_PRIOR"},
            {SDLK_RETURN2, "SDLK_RETURN2"},
            {SDLK_SEPARATOR, "SDLK_SEPARATOR"},
            {SDLK_OUT, "SDLK_OUT"},
            {SDLK_OPER, "SDLK_OPER"},
            {SDLK_CLEARAGAIN, "SDLK_CLEARAGAIN"},
            {SDLK_CRSEL, "SDLK_CRSEL"},
            {SDLK_EXSEL, "SDLK_EXSEL"},
            {SDLK_KP_00, "SDLK_KP_00"},
            {SDLK_KP_000, "SDLK_KP_000"},
            {SDLK_THOUSANDSSEPARATOR, "SDLK_THOUSANDSSEPARATOR"},
            {SDLK_DECIMALSEPARATOR, "SDLK_DECIMALSEPARATOR"},
            {SDLK_CURRENCYUNIT, "SDLK_CURRENCYUNIT"},
            {SDLK_CURRENCYSUBUNIT, "SDLK_CURRENCYSUBUNIT"},
            {SDLK_KP_LEFTPAREN, "SDLK_KP_LEFTPAREN"},
            {SDLK_KP_RIGHTPAREN, "SDLK_KP_RIGHTPAREN"},
            {SDLK_KP_LEFTBRACE, "SDLK_KP_LEFTBRACE"},
            {SDLK_KP_RIGHTBRACE, "SDLK_KP_RIGHTBRACE"},
            {SDLK_KP_TAB, "SDLK_KP_TAB"},
            {SDLK_KP_BACKSPACE, "SDLK_KP_BACKSPACE"},
            {SDLK_KP_A, "SDLK_KP_A"},
            {SDLK_KP_B, "SDLK_KP_B"},
            {SDLK_KP_C, "SDLK_KP_C"},
            {SDLK_KP_D, "SDLK_KP_D"},
            {SDLK_KP_E, "SDLK_KP_E"},
            {SDLK_KP_F, "SDLK_KP_F"},
            {SDLK_KP_XOR, "SDLK_KP_XOR"},
            {SDLK_KP_POWER, "SDLK_KP_POWER"},
            {SDLK_KP_PERCENT, "SDLK_KP_PERCENT"},
            {SDLK_KP_LESS, "SDLK_KP_LESS"},
            {SDLK_KP_GREATER, "SDLK_KP_GREATER"},
            {SDLK_KP_AMPERSAND, "SDLK_KP_AMPERSAND"},
            {SDLK_KP_DBLAMPERSAND, "SDLK_KP_DBLAMPERSAND"},
            {SDLK_KP_VERTICALBAR, "SDLK_KP_VERTICALBAR"},
            {SDLK_KP_DBLVERTICALBAR, "SDLK_KP_DBLVERTICALBAR"},
            {SDLK_KP_COLON, "SDLK_KP_COLON"},
            {SDLK_KP_HASH, "SDLK_KP_HASH"},
            {SDLK_KP_SPACE, "SDLK_KP_SPACE"},
            {SDLK_KP_AT, "SDLK_KP_AT"},
            {SDLK_KP_EXCLAM, "SDLK_KP_EXCLAM"},
            {SDLK_KP_MEMSTORE, "SDLK_KP_MEMSTORE"},
            {SDLK_KP_MEMRECALL, "SDLK_KP_MEMRECALL"},
            {SDLK_KP_MEMCLEAR, "SDLK_KP_MEMCLEAR"},
            {SDLK_KP_MEMADD, "SDLK_KP_MEMADD"},
            {SDLK_KP_MEMSUBTRACT, "SDLK_KP_MEMSUBTRACT"},
            {SDLK_KP_MEMMULTIPLY, "SDLK_KP_MEMMULTIPLY"},
            {SDLK_KP_MEMDIVIDE, "SDLK_KP_MEMDIVIDE"},
            {SDLK_KP_PLUSMINUS, "SDLK_KP_PLUSMINUS"},
            {SDLK_KP_CLEAR, "SDLK_KP_CLEAR"},
            {SDLK_KP_CLEARENTRY, "SDLK_KP_CLEARENTRY"},
            {SDLK_KP_BINARY, "SDLK_KP_BINARY"},
            {SDLK_KP_OCTAL, "SDLK_KP_OCTAL"},
            {SDLK_KP_DECIMAL, "SDLK_KP_DECIMAL"},
            {SDLK_KP_HEXADECIMAL, "SDLK_KP_HEXADECIMAL"},
            {SDLK_LCTRL, "SDLK_LCTRL"},
            {SDLK_LSHIFT, "SDLK_LSHIFT"},
            {SDLK_LALT, "SDLK_LALT"},
            {SDLK_LGUI, "SDLK_LGUI"},
            {SDLK_RCTRL, "SDLK_RCTRL"},
            {SDLK_RSHIFT, "SDLK_RSHIFT"},
            {SDLK_RALT, "SDLK_RALT"},
            {SDLK_RGUI, "SDLK_RGUI"},
            {SDLK_MODE, "SDLK_MODE"},
            {SDLK_AUDIONEXT, "SDLK_AUDIONEXT"},
            {SDLK_AUDIOPREV, "SDLK_AUDIOPREV"},
            {SDLK_AUDIOSTOP, "SDLK_AUDIOSTOP"},
            {SDLK_AUDIOPLAY, "SDLK_AUDIOPLAY"},
            {SDLK_AUDIOMUTE, "SDLK_AUDIOMUTE"},
            {SDLK_MEDIASELECT, "SDLK_MEDIASELECT"},
            {SDLK_WWW, "SDLK_WWW"},
            {SDLK_MAIL, "SDLK_MAIL"},
            {SDLK_CALCULATOR, "SDLK_CALCULATOR"},
            {SDLK_COMPUTER, "SDLK_COMPUTER"},
            {SDLK_AC_SEARCH, "SDLK_AC_SEARCH"},
            {SDLK_AC_HOME, "SDLK_AC_HOME"},
            {SDLK_AC_BACK, "SDLK_AC_BACK"},
            {SDLK_AC_FORWARD, "SDLK_AC_FORWARD"},
            {SDLK_AC_STOP, "SDLK_AC_STOP"},
            {SDLK_AC_REFRESH, "SDLK_AC_REFRESH"},
            {SDLK_AC_BOOKMARKS, "SDLK_AC_BOOKMARKS"},
            {SDLK_BRIGHTNESSDOWN, "SDLK_BRIGHTNESSDOWN"},
            {SDLK_BRIGHTNESSUP, "SDLK_BRIGHTNESSUP"},
            {SDLK_DISPLAYSWITCH, "SDLK_DISPLAYSWITCH"},
            {SDLK_KBDILLUMTOGGLE, "SDLK_KBDILLUMTOGGLE"},
            {SDLK_KBDILLUMDOWN, "SDLK_KBDILLUMDOWN"},
            {SDLK_KBDILLUMUP, "SDLK_KBDILLUMUP"},
            {SDLK_EJECT, "SDLK_EJECT"},
            {SDLK_SLEEP, "SDLK_SLEEP"},
            {SDLK_APP1, "SDLK_APP1"},
            {SDLK_APP2, "SDLK_APP2"},
            {SDLK_AUDIOREWIND, "SDLK_AUDIOREWIND"},
            {SDLK_AUDIOFASTFORWARD, "SDLK_AUDIOFASTFORWARD"},
        };

        for( int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); i++)
        {
            keyMap[pairs[i].key] = pairs[i].name;
        }
    }

    std::map<SDL_Keycode, std::string>::iterator itr = keyMap.find(key);
    if( itr == keyMap.end() )
    {
        return std::string("UNKNOWN KEY");
    }

    return itr->second;
}