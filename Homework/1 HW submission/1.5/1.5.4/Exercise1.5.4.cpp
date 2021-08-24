#include <stdio.h>


//Function to count the number of digit the given integer has
int count_digit(int num)
{
	int n = 0;
	if (num < 0) { num = -num;};
	if (num == 0) { return 1; }

	while (num != 0)
	{
		num /= 10;
		n++;
	}
	return n;
}

//Calculat 10 to the power n
int power(int n)
{
	int res;
	for (res = 1; n > 0; n--) { res *= 10; };
	return res;
}

void printnumber(int num, int n_digit)
{
	int digit, top_place, remainder;
	
	//Deal with negative conditions
	if (num < 0)
	{
		num = -num;
		putchar(45);
	}

	//The last time recurse
	if (n_digit == 1)
	{
		putchar(num + 48);
		return;
	}

	top_place = power(n_digit - 1);
	remainder = num % top_place;
	digit = (num - remainder) / top_place;
	putchar(digit + 48);
	
	printnumber(remainder, n_digit - 1);
};


int main()
{
	int num;
	printf("Please enter an integer between %d and %d\n", -2147483647, 2147483647);
	scanf_s("%d", &num);
	printnumber(num, count_digit(num));

	return 0;
}