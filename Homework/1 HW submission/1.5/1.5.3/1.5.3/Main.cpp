#include <stdio.h>


float i;
void print(float);
int main()
{
	printf("Please give i a value:\n");
	scanf_s("%f", &i);
	print(i);
	
	return 0;
}