#include <SDL.h>
#include <stdlib.h>

void my_audio_callback(void *userdata, Uint8 *stream, int len);

static Uint8 *audio_pos;
static Uint32 audio_len;


int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_AUDIO);

    static Uint32 wav_length;
    static Uint8 *wav_buffer;
    static SDL_AudioSpec wav_spec;

    if( ! SDL_LoadWAV("harmonica.wav", &wav_spec, &wav_buffer, &wav_length) )
        return 1;

    wav_spec.callback = my_audio_callback;
    wav_spec.userdata = NULL;

    audio_pos = wav_buffer;
    audio_len = wav_length;

    if( SDL_OpenAudio(&wav_spec, NULL) < 0 )
    {
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
        exit(-1);
    }

    SDL_PauseAudio(0);  /* This starts playing */

    while( audio_len > 0 )
    {
        SDL_Delay(100);
    }

    SDL_CloseAudio();
    SDL_FreeWAV(wav_buffer);
}


void my_audio_callback(void *userdata, Uint8 *stream, int len)
{
    if (audio_len ==0)
        return;

    if( len > audio_len )
        len = audio_len;

    SDL_memcpy( stream, audio_pos, len );

    audio_pos += len;
    audio_len -= len;
}

