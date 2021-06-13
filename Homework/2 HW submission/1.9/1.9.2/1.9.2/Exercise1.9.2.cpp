/*Read the characters from the keybord and write them on a file once hit 'enter'.
Finish the program when ^A is entered with an ending sentence*/
#include <stdio.h>

int main()
{
	char filename[20];			//	Declare filename, with max of 20 chars
	// Intro text
	printf("please enter file name ending with .txt\n");
	scanf_s("%19s", &filename, 20);
	printf("Please enter some content. Those will be saved to a file.\nEnter CTRL + A to quit\n");
	getchar();					// eat out the Enter after filename

	/*Declare a file with the filename just entered, failed if the file not open*/
	FILE* fp;
	errno_t err = fopen_s(&fp, filename, "w");
	if (err != 0) { printf("File was not opend\n"); };

	int c = getchar();			//	Declare character c, with value of first input
	while (c != 1)				//	get and print the value until ^A has been input
	{
		fputc(c, fp);			//	write the contents to the file
		c = getchar();			//	get the next character for loop
	}
	/*print out ending sentence. ^A is Shift + Ctrl + A on my computer, but it makes sense here*/
	printf("\nCTRL + A is a correct ending");
	return 0;
}