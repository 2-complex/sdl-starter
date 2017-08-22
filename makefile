
SDL_STATIC_LIBS = \
	-L/usr/local/lib \
	-lSDL2 \
	-lm \
	-liconv \
	-Wl,-framework,OpenGL \
	-Wl,-framework,ForceFeedback \
	-Wl,-framework,Cocoa \
	-Wl,-framework,Carbon -Wl,-framework,IOKit \
	-Wl,-framework,CoreAudio \
	-Wl,-framework,AudioToolbox \
	-Wl,-framework,AudioUnit

SDL_C_FLAGS = \
	-I/usr/local/include/SDL2 \
	-D_THREAD_SAFE

run: events
	./events

sdl: SDL-mirror


events: sdl events.cpp
	c++ \
		events.cpp -o events \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

flash: sdl flash.cpp
	c++ \
		flash.cpp -o flash \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

SDL-mirror:
	git submodule init
	git submodule update --recursive
