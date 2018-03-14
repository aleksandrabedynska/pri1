#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

unsigned long long int factorial(int m);
long double exp_squar(double a, int m);

void main()
{
	int n = 0;		// accuracy of the series
	double x = 0.0f;	// argument for the function
	long double error = 0.0f; 	
	double ctgh_m = 0.0f;
	long double ctgh = 0.0f;
	long double numerator = 0.0f;
	long double denominator = 0.0f;
	double tgh = 0.0f;

	printf("Type the argument for hyperbolic cotangens function (x) \n");
	scanf("%lf", &x);
	printf("Type the desired accuracy of series (n) \n");
	scanf("%d", &n);
	if (n > 0 && round(n) == n)
	{
		tgh= tanh(x);
		ctgh_m = 1. / tgh;
		printf("tanh = %lf \n",tgh);
		for (int i = 0; i < n + 1; i++)
		{
			numerator = numerator + exp_squar(x, 2 * i) / factorial(2 * i);
		}
		for (int i = 0; i < n + 1; i++)
		{
			denominator = denominator + exp_squar(x, 2 * i + 1) / factorial(2 * i + 1);
		}
		if (denominator == 0)
		{
			printf("Invalid input, division by 0");
			exit(1);
		}
		ctgh = numerator / denominator;
		printf("The value of hyperbolic cotangens derived from series is: %Lf \n", ctgh);
		printf("The value of hyperbolic cotangens calculated by math.h library is: %lf \n", ctgh_m);
		error = (ctgh - ctgh_m) / ctgh_m * 100.0f;
		printf("Error equals to : %Lf %%", error);

	}
	else
	{
		printf("invalid value of n : termination tiggered \n");
		//exit(1);
	}
	
	exit(0);
}
unsigned long long int factorial(int m)
{
	if (m == 0)
		return 1;
	else
		return (m*factorial(m - 1));
}
long double exp_squar(double a, int m)
{
	if (m == 0)
		return 1;
	else
		if (m == 1)
		return a;
	else
		if (m % 2 == 0)
		return exp_squar(a*a, m / 2);
	
	else
		if (m % 2 == !0)
		return (a*exp_squar(a*a, (m - 1) / 2));
	else
		return 0;
}
