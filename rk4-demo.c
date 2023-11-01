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
	int numberOfForces;
	/* charge and mass are defined in terms of the electron */
	double charge;
	double mass;
	/* position velocity and force. Acceleration can be found through a=f/m */
	Vector2 position;
	Vector2 velocity;
} particle;

double rk4solver(double x0, double y0, double h, double (*function)(double, double)){
	double k1, k2, k3, k4;
	k1 = (*function)(x0, y0);
	k2 = (*function)(x0 + h/2, y0 + (h * k1)/2);
	k3 = (*function)(x0 + h/2, y0 + (h * k2)/2);
	k4 = (*function)(x0 + h, y0 + (h * k3));
	return y0 + (h/6)*(k1 + 2*k2 + 2*k3 +k4);
}

Vector2 eletricForce(particle *a, particle *b){
	return { (K * a -> charge * b -> charge)/(pow(b -> position.x - a -> position.x, 2) + pow(b -> position.y - a -> position.y, 2)) * (b - a)/ pow(b - a, 1/2) };
}

void moveParticle(particle *a, float deltaTime){
	a -> position.x =
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
