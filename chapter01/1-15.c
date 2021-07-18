/*
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

float celsius(float fahr);

int main(void)
{
	float fahr;
	int lower = 0, upper = 300, step = 20;

	printf("Fahr Celsius\n");

	fahr = lower;

	while (fahr <= upper)
	{
		printf("%3.0f  %6.1f\n", fahr, celsius(fahr));
		fahr += step;
	}
}

float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
