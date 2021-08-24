#include <stdio.h>


void print(float)
{
	extern float i;
	float res = 2 * i;
	printf("2i = %.2f\n", res);
	return;
}