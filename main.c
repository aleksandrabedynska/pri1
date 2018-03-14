#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int factorial(int m);	// funcja liczaca silnie z liczby algorytmem rekurencyjnym, zwraca wartosc typu unsigned long long int aby liczyla silnie z mozliwie duzej liczby
long double exp_squar(double a, int m);		//funkcja wykonujaca potegowanie liczby algorytmem szybkiego potegowania, zwraca wartosc typu long double

void main()
{
	int n = 0;			//dokladnosc rozwiniecia w szereg
	double x = 0.0f;		//argument funkcji
	long double error = 0.0f; 	// blad miedzy wartoscia funkcji obliczona z funkcji z math.h a wartoscia obliczona poprzez rozwiniecie w szereg
	double ctgh_m = 0.0f;		// zmienna przechowujaca wartosc funkcji kotangens hiperboliczny obliczona za pomoca odwrotnosci funkcji tangens hiperboliczny zawartej w bibliotece math.h
	long double ctgh = 0.0f;	// zmienna przechowaujaca wartosc funkcji kotangens hiperboliczny obliczonej przez rozwiniecie w szereg
	long double numerator = 0.0f;		// licznik 
	long double denominator = 0.0f;		//mianownik
	double tgh = 0.0f;		//zmienna pomocnicza podajaca wartosc tangensa hiperbolicznego obliczonego korzystajac z funkcji z biblioteki math.h

	printf("Type the argument for hyperbolic cotangens function (x) \n");
	scanf("%lf", &x);
	printf("Type the desired accuracy of series (n) \n");
	scanf("%d", &n);
	if (n > 0 && round(n) == n)		//petla realizujaca program jesli podana przez uzytkownika funkcja n jest liczba dodatnia i calkowita
	{
		tgh= tanh(x);
		ctgh_m = 1. / tgh;
		//printf("tanh = %lf \n",tgh);
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
