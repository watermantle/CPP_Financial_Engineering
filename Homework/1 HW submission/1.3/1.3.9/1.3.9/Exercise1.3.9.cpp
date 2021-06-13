#include <stdio.h>

int main()
{
	int x = 1;
	int y = 1;
	int z = 1;

	x += y += x;
	printf("%d\n", (x < y) ? y : x); // Number_1 = 3
	printf("%d\n", (x < y) ? x++ : y++); // Number_2 = 2
	printf("%d\n", x); // Number_3 = 3
	printf("%d\n", y); // Number_4 = 3

	return 0;
}