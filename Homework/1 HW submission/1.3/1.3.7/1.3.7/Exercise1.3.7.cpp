#include <stdio.h>

int main()
{
	int a, n;
	
	printf("Enter an integer a\n");
	scanf_s("%d", &a);
	printf("Enter the power n\n");
	scanf_s("%d", &n);
	printf("%d multiplied by 2 to power of %d is %d", a, n, a << n);

	return 0;
 }