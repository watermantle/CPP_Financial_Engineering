#include <stdio.h>

int main()
{
	int num;

	printf("Please enter an integer, we will shift the number two places to the right\n");
	scanf_s("%d", &num);

	printf("The shifted number is %d, %s shift is performed",  num >> 2, num < 0 ? "an Arithmetic" : "a Logical");
	
	return 0;
}