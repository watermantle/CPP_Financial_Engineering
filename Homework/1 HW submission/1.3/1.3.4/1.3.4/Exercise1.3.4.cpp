#include <stdio.h>

int main()
{
	int married;

	printf("Enter 0 if you are single, otherwise enter any non-zero integer\n");
	scanf_s("%d", &married);

	printf("You are %s", married == 0 ? "unmarried" : "married");

	return 0;
}