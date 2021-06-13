#include <stdio.h>

int main()
{
	float height, base;

	printf("To calculate the surface of a right triangle, please enter the height\n");
	scanf_s("%f", &height);

	printf("Please enter the base\n");
	scanf_s("%f", &base);

	float surface = (height * base) * 0.5f;
	printf("The surface is %0.2f", surface);

	return 0;
}