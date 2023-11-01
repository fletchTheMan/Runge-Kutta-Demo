#include <stdio.h>
#include <math.h>

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

double functA(double x, double y){
	return -2 * y + pow(x, 3) * pow(2.71828182845904523536, -2 * x);
}

double functB(double x, double y){
	return (pow(2.71828182845904523536, -2*x) * pow(x, 3)) - (2 * y);
}

int main(){
	int i;
	double y, x;
	x = 0;
	y = 1;
	printf("functA\n");
	for(i = 0; i < 20; i++){
		x += 0.1;
		y = rk4solver(x , y, 0.1, functA);
		printf("x: %lf, y: %.10lf\n", x, y);
	}
	printf("end functA\nBegin functB\n");
	y = 1;
	x = 0;
	for(i = 0; i < 20; i++){
		x += 0.1;
		y =rk4solver(x, y, 0.1, functB);
		printf("x: %lf, y: %.10lf\n", x, y);
	}
	printf("end functB\n");
	return 0;
}
