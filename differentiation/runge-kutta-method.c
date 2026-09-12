#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define e 2.718281828459045

/* Runge-Kutta Method
 */

double f(double x, double y)
{
	return 2 - pow(e, (-4*y)) - (2*x);
}

int main()
{
	int steps;
	double y0;

	printf("Enter total number of steps to process: "); //To do: Error loop if int not received 
	scanf("%d", &steps);

	printf("Enter initial value: "); //To do: Error loop if double not entered
	scanf("%lf", &y0);

	FILE *stream;
	stream = fopen("output.txt", "w");
	fprintf(stream, "time\tvalue\n");

	double h = 0.0005; //Stepsize
	int count = 0;
	double x, xnew, y, ynew, k1, k2, k3, k4; 

	x = 0;
	y = y0;

	while(count < steps)
	{
		k1 = h*f(x, y);
		k2 = h*f((x+(h/2)), (y+(k1/2)));
		k3 = h*f((x+(h/2)), (y+(k2/2)));
		k4 = h*f((x+h), (y+k3));

		xnew = x + h;
		ynew = y + (k1/6) + (k2/3) + (k3/3) + (k4/6);

		fprintf(stream, "%lf\t%lf\n", xnew, ynew);

		count++;
		x = xnew;
		y = ynew;
	}

	fclose(stream);

	return 0;
}


