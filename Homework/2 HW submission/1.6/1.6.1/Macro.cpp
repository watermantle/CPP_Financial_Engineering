//	Print values by using macro calls that are defined in Defs.hpp
#include <stdio.h>
#include "Defs.h"		//	include Defs.h


int main()
{
	int a, b;
	printf("Please enter an integer a\n"); 
	scanf_s("%d", &a);	//	To get value a from user
	printf("Please enter an integer b\n"); 
	scanf_s("%d", &b);	//	To get value b from user
	
	PRINT1(a);			//	Call PRINT1 to print the value a 
	PRINT2(a, b);		//	Call PRINT2 to print the value a and b 
	return 0;
}