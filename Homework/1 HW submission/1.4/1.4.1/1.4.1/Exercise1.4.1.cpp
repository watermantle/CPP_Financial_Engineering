#include <stdio.h>


/* Function to check if a char is a letter */
bool isalpha(char c) {
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}


int main()
{
	int cntr_words = 0, cntr_chars = 0, cntr_ls = 0; // cunters for words, chars, and lines
	char c, c0; // c is current char, c0 is to remember the previous char

	c = getchar();
	c0 = c;

	while (c0 != 4)
	{
		cntr_chars++;

		if (isalpha(c0) && !isalpha(c)) cntr_words++;
		// count word if previous char is a letter but the current is not
	
		c0 = c;
		c = getchar();
		if (c == '\n') cntr_ls++;
	};

	printf("The number of words is %d\n", cntr_words);
	printf("The number of chars is %d\n", cntr_chars > 0? cntr_chars - 1 : 0);
	printf("The number of new lines is %d\n", cntr_ls);
	// ^D + Enter to quit the app, resonable to star from 0.

	return 0;
}