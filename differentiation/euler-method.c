#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
#define e 2.718281828459045

/* Euler's Method For Solving Ordinary Differential Equations
 * Enter your formula on the return line of the function f below.
 * At runtime, program prompts user for the total steps, step size
 * and initial value.
 * Max iterations are defined by MAX above.
 * Output written to output.txt with the following format:
 * iteration_count	time	approximation
 * 
 */

double f(double x, double t)
{
	return 2 - pow(e, (-4*t)) - (2*x);
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
	double y, t, m, ynew, tnew;

	t = 0;
	y = y0;

	while(count < steps)
	{
		m = f(y, t);
		ynew = y + (m*stepsize);
		tnew = t + stepsize;
		fprintf(stream, "%lf\t%lf\n", tnew, ynew);

		count++;
		y = ynew;
		t = tnew;	
	}

	fclose(stream);

	return 0;
}


