
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

BIN = bin


run: $(BIN)/windows
	./$(BIN)/windows

all: \
	$(BIN)/flash \
	$(BIN)/events \
	$(BIN)/windows

SDL-mirror/Makefile: SDL-mirror/configure
	cd SDL-mirror && ./configure

sdl: SDL-mirror/Makefile
	cd SDL-mirror && make install

SDL-mirror/configure:
	git submodule init
	git submodule update --recursive

$(BIN)/loadbmp: sdl loadbmp.cpp
	c++ \
		loadbmp.cpp -o $(BIN)/loadbmp \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

$(BIN)/events: sdl events.cpp
	c++ \
		events.cpp -o $(BIN)/events \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

$(BIN)/windows: sdl windows.cpp
	c++ \
		windows.cpp -o $(BIN)/windows \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

$(BIN)/flash: sdl flash.cpp
	c++ \
		flash.cpp -o $(BIN)/flash \
		$(SDL_C_FLAGS) \
		$(SDL_STATIC_LIBS)

clean:
	-rm -f bin/*

