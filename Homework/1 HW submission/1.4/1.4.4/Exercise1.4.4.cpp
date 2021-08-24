#include <stdio.h>


int main()
{
	float Fah_s=0, Fah_e=300, step_f=20, Cel, Fah;
	
	printf("Step up temperatures in Fahrenheit start from %0.1f to %0.1f", Fah_s, Fah_e);
	printf(" with step of %0.1f. Celsius degrees attched.\n", step_f);
	printf("     T in F \tT in C\n");

	Fah = Fah_s;
	while (Fah <= Fah_e)
	{
		Cel = (Fah - 32) * 5 / 9;
		printf("%10.1f, %10.1f\n", Fah, Cel);
		Fah += step_f;
	}
	return 0;
}