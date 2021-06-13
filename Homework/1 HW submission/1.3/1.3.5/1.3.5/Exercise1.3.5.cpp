#include <stdio.h>


int main()
{
	int i = 10, res = 0;

	printf("Let i = 10, the result will be %d if we set res = --i;\n", res = --i); // res=9
	
	i = 10, res = 0;
	
	printf("The reulst will be %d if we set res = i--", res = i--); // res=10

	return 0;
}