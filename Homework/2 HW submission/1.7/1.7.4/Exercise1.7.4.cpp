/*	Create and call function DayName() to print the day of a given day-number*/
#include <stdio.h>

void DayName(int i)
{
	//	Multidimensional array 7 for 7 days, 10 for the max # of char, Wednesdays. 9 + 1 ('\0')
	char days[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	//	Print the a string representing day
	printf("%s", days[i - 1]);
}

int main()
{
	int i;	// the day-number
	printf("Enter a day-number from 1-7. 1 is Sunday, 7 is Satruday\n");	//	Print intro text
	scanf_s("%d", &i);
	printf("%d gives: Day %d is ", i, i);
	DayName(i);	//	Call function Dayname() to print the day of a given day-number
	return 0;
}