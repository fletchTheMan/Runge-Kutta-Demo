#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

typedef struct {
	Vector2 position;
	Vector2 velocity;
	Vector2 *force;
} particle;

int main(){
	particle testParticle = { { 0.0, 0.0 }, { 0.0, 0.0 } };
	testParticle.force = (Vector2*)malloc(sizeof(Vector2) * 5);
	testParticle.force[0] = (Vector2){ 0.0, 0.0};
	testParticle.force[1] = (Vector2){ 1.0, 1.0};
	printf("%f\t %f\n", testParticle.force[1].x, testParticle.force[0].x);
	free(testParticle.force);
}
