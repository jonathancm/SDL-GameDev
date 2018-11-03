# CFLAGS=-c -Wall
# #LDFLAGS=
# SOURCES=main.cpp hello.cpp factorial.cpp
# OBJECTS=$(SOURCES:.cpp=.o)
# EXECUTABLE=hello

# all:
# 	$(CC) $(CFLAGS) main.cpp hello.cpp factorial.cpp -o hello

# clean:
# 	rm -rf *o hello


#Taken from http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-linux-command-line/
CXX = g++
# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = SDL_test

all: $(EXE)

$(EXE): main.o
	$(CXX) $< $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)