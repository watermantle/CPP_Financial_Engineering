/*Read the characters from the keybord and show them on screen once hit 'enter'.
Finish the program when ^A is entered with an ending sentence*/
#include <stdio.h>

int main()
{
	int c = getchar();		//	Declare character c, with value of first input
	while (c != 1)			//	get and print the value until ^A has been input
	{
		putchar(c);			//	print the value c on screen
		c = getchar();		//	get the next character for loop
	}
	/*print out ending sentence. ^A is Shift + Ctrl + A on my computer, but it makes sense here*/
	printf("\nCTRL + A is a correct ending");
	return 0;
}