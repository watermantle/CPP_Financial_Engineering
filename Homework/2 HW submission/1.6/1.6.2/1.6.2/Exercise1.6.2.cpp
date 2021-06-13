//	Ask user to enter three numbers x, y, z. Print max of x, y by calling macro MAX2 defined in Defs.h
//	Then print max of x, y, z by calling macro MAX3 defined in Defs.h
#include "Defs.h"	//	include file Defs.h where MAX2 and MAX3 have been defined
#include <stdio.h>

int main()
{
	float x, y, z;
	//	Ask user to enter three numbers x, y, z and save them.
	printf("Please enter x\n");
	scanf_s("%f", &x);
	printf("Please enter y\n");
	scanf_s("%f", &y);
	printf("Please enter z\n");
	scanf_s("%f", &z);

	//	Print results by calling MAX2, MAX3. The results should keep 4 decimal places.
	printf("The max of x and y is %0.4f\n", MAX2(x, y));
	printf("The max of x, y, and z is %0.4f", MAX3(x, y, z));
	return 0;
}