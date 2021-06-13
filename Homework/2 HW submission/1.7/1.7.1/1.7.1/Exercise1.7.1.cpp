//	function Swap() with pointers as arguments. To swap the value of two variables i, j
#include <stdio.h>

//	Swap function declaration
void Swap(float* i, float* j);

int main()
{
	float i, j;
	printf("Please enter i:\n"); scanf_s("%f", &i);	//	Ask input i
	printf("Please enter j:\n"); scanf_s("%f", &j);	//	Ask input j
	Swap(&i, &j);									//	Call Swap function to swap i and j
	printf("The swapped values are i=%0.4f, j=%0.4f", i, j);	//	Print out the swapped values
	return 0;
}

//Swap function to swap two values
void Swap(float* i, float* j)
{
	float temp; //	temp varible to store intermediary value
	//exchange the values by c = a, a = b, b = c;
	temp = *i;
	*i = *j;
	*j = temp;
}