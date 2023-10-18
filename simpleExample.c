#include <stdio.h>
#include <math.h>

/*
 * Example of passing a function as an argument
void print(float x, float y){
	printf("%f, %f\n", x, y);
}

void func ( void (*f)(float, float)) {
	for(int i = 0; i < 5; i++){
		(*f)((float)i, (float)i);
	}
}
*/

/* y' = sin(t)^2 
dy/dt = f(t,y) y(t0) = y0
y1=y0 + h/6(k1 + 2k2 + 2k3 + k4)
k1 = f(t0, y0)
k2 = f(t0 + h/2, y0 + (h * k1)/2)
k3 = f(t0 + h/2, y0 + (h * k2)/2)
k4 = f(t0 + h, y0 + h * k3)
*/

double rk4solver(double x0, double y0, double h, double (*function)(double, double)){
	double k1, k2, k3, k4;
	k1 = (*function)(x0, y0);
	k2 = (*function)(x0 + h/2, y0 + (h * k1)/2);
	k3 = (*function)(x0 + h/2, y0 + (h * k2)/2);
	k4 = (*function)(x0 + h, y0 + (h * k3));
	return y0 + (h/6)*(k1 + 2*k2 + 2*k3 +k4);
}

double funct(double x, double y){
	return -2 * y + pow(x, 3) * pow(2.71828182845904523536, -2 * x);
}


/*
double position(double x0, double v0){
	return 0;
}
double velocity(double v0, double (*f)(double)){
	return 0;
}
double acceleration(double netForce){
	return 0;
}
*/


int main(){
	double y1 = rk4solver(0, 1, 0.1, funct);
	printf("%.10lf\n", y1);
	printf("%.10lf\n", rk4solver(0.1, y1, 0.1, funct));
	return 0;
}
