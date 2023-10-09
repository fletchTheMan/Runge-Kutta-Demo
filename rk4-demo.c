#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
/* Proton is about 1836 times the mass of an electron
 * Neutron mass is the same but since it has 0 charge it is not interesting */
#define ProtonMass 1836
#define K 8.987 * pow(10, 9)
/* If converting to SI unit use doubles NOT floats because it is too close 
 * to the for comfort */
#define ElectronMass 9.109 * pow(10, -31)
#define ElectronCharge -1.602 * pow(10, -19);

/* A Struct to use particles can use any units but defaults to in terms of electron
 * so that the values can be integers */
typedef struct particle {
	/* charge and mass are defined in terms of the electron */
	double charge;
	double mass;
	/* position velocity and force. Acceleration can be found through a=f/m */
	Vector2 position;
	Vector2 velocity;
	Vector2 fnet;
} particle;

/* Returns 0 for an error and 1 for success */
int addForce(particle* a, Vector2 addedForce){
	if(a == NULL){
		fprintf(stderr, "particle is null");
		return 0;
	}
	else {
		a->fnet.x += addedForce.x;
		a->fnet.y += addedForce.y;
		return 1;
	}
}

void moveParticle(particle *a, float deltaTime){

}

int main(){
	char name[] = "Runge-Kutta 4 Demo";
	char* outString;
	int screenHeight = 1080;
	int screenWidth = 1920;
	InitWindow(screenWidth, screenHeight, name);
	outString = (char*)malloc(100 * sizeof(char));
	SetTargetFPS(600);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		snprintf(outString, 100, "Simple Window\nFPS:%d\n%f", GetFPS(), K);
		DrawText(outString, 190, 200, 20, RED);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
