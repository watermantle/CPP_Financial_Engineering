#include <stdio.h>


int factorials(int num)
{
	int res;
	if (num == 0 || num == 1) res = 1;
	else
	{
		res = num * factorials(num - 1);
	}
	return res;
}

int main()
{
	int num;
	printf("Please enter positive integer that should be less than 13\n");
	scanf_s("%d", &num);
	printf("The factorial of %d is %d", num, factorials(num));
	
	return 0;
}