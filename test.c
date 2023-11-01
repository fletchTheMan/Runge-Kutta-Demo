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
	k2 = (*function)(x0 + h/2, y0 + h / 2 * k1);
	k3 = (*function)(x0 + h/2, y0 + h / 2 * k2);
	k4 = (*function)(x0 + h, y0 + (h * k3));
	return y0 + (h/6)*(k1 + 2*k2 + 2*k3 +k4);
}

double functA(double x, double y){
	return -2 * y + pow(x, 3) * pow(2.71828182845904523536, -2 * x);
}

double functB(double x, double y){
	return 1 + 2 * x * y;
}

int main(){
	int i;
	double y, x, h;
	x = 0;
	y = 1;
	printf("functA\n");
	for(i = 0; i < 20; i++){
		y = rk4solver(x , y, 0.1, functA);
		/* REMEBER to do the incementing of x AFTER calling rk4solver 
		 * OR the value will be off, sometimes it is just the next
		 * othertimes it wil change the value signifgantly */
		x += 0.1;
		printf("x: %lf, y: %.10lf\n", x, y);
	}
	printf("end functA\nBegin functB\n");
	y = 3;
	x = 0;
	h = 0.05;
	for(; x < 2.0; ){
		y = rk4solver(x, y, h, functB);
		x += h;
		printf("x: %lf, y: %.10lf\n", x, y);
	}
	printf("end functB\n");
	return 0;
}
