#include <stdio.h>


float minus(float a, float b)
{
	return a - b;
}

int main()
{
	float a, b;
	
	printf("Please enter the first number\n");
	scanf_s("%f", &a);
	printf("Please enter the second number\n");
	scanf_s("%f", &b);

	printf("The difference is %.2f", minus(a, b));
	 
	return 0;
}