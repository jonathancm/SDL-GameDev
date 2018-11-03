#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "cartesianVector2D.h"

int main(int argc, char **argv)
{

	// Vector2D* vec1;
	// Vector2D* vec2;
	// Vector2D* vec3;

	// vec1 = new Vector2D(10,20);
	// vec2 = new Vector2D(2,3);
	// vec2 = new Vector2D();

	Vector2D vec1(10,20);
	Vector2D vec2(2,3);

	//Vector2D vec( (vec1 + vec2).getX(),(vec1 + vec2).getY()) ;
	vec1+=vec2;

	printf("X=%f, Y=%f\n",vec2.getX(),vec2.getY());
	printf("X=%f, Y=%f\n",vec1.getX(),vec1.getY());

	return 0;
}