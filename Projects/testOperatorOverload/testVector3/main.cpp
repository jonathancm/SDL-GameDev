#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "cartesianVector2D.h"

int main(int argc, char **argv)
{
	Vector2D vec1(10,20);
	Vector2D vec2(2,3);

	vec1+=vec2;

	printf("X=%f, Y=%f\n",vec2.getX(),vec2.getY());
	printf("X=%f, Y=%f\n",vec1.getX(),vec1.getY());

	return 0;
}