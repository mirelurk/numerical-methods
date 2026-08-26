#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define e 2.718281828459045

/* Runge-Kutta Method
*
 */

double f(double x, double y)
{
	return 2 - pow(e, (-4*y)) - (2*x);
}

int main()
{

	int steps;
	double stepsize;
	double y0;

	printf("Enter total steps: "); //Error loop if int not entered or if step > MAX
	scanf("%d", &steps);

	printf("Enter step size: "); //Error loop if double not entered
	scanf("%lf", &stepsize);

	printf("Enter initial value: "); //Error loop if double not entered
	scanf("%lf", &y0);

	FILE *stream;
	stream = fopen("output.txt", "w");
	fprintf(stream, "time\tvalue\n");

	int count = 0;
	double x, xh, y, yh, k1, k2;

	x = 0;
	y = y0;

	while(count < steps)
	{
		k1 = stepsize * f(x,y);
		xh = x + (stepsize/2);
		yh = y + (k1/2);
		k2 = stepsize * f(xh, yh);

		ynew = y + k2 + O(stepsize^3); //Need to create error function O
		xnew = x + stepsize;
		y = ynew;
		x = xnew;
		count++;
	}

	fclose(stream);

	return 0;
}


