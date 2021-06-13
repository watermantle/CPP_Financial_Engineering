#include <stdio.h>


int main()
{
	float Cel_s = 0, Cel_e = 19, step_c = 1, Cel, Fah;
	
	printf("Step up temperatures in Celsius start from %0.1f to %0.1f", Cel_s, Cel_e);
	printf(" with step of %0.1f. Fahrenheit degrees attched.\n", step_c);
	printf("     T in C \tT in F\n");

	for (Cel = Cel_s; Cel <= Cel_e; Cel += step_c)
	{ 
		Fah = 32 + Cel * 9 / 5;
		printf("%10.1f, %10.1f\n", Cel, Fah);
	}
	return 0;
}