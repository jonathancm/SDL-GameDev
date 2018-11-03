# Compiler is g++
CXX = g++

# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
#SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_mixer -Wl,-rpath=/usr/local/lib 
SDL_INCLUDE = -I/usr/include

# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = SDLChapter5.0

all: $(EXE)

#OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
OBJECTS= Game.o TextureManager.o Player.o Enemy.o SDLGameObject.o main.o InputHandler.o state_Menu.o state_Play.o GameStateMachine.o

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)