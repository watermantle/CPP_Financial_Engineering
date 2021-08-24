#include <stdio.h>


/* Function to check if a char is a letter */
bool isalpha(char c) {

	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}


int main()
{
	int cntr_words = 0, cntr_chars = 0, cntr_ls = 1; // cunters for words, chars, and lines
	char c, c0; // c is current char, c0 is to remember the previous char

	c = getchar();
	c0 = c;

	while (c0 != 4)
	{
		cntr_chars++;

		int x = 100 * (isalpha(c0) && !isalpha(c)) + 10 * (c == '\n');
		// True is 1, False is 0, different conbination to execute 

		switch (x)
		{
		case 0:
			break;
		case 10:
			cntr_ls++;
			break;
		case 100:
			cntr_words++;
			break;
		case 110:
			cntr_ls++;
			cntr_words++;
			break;
		}

		c0 = c;
		c = getchar();
	};

	cntr_chars = cntr_chars > 0 ? cntr_chars - 1 : 0;
	if (cntr_chars == 0 && cntr_words == 0) { cntr_ls = 0; }; //In case only input is ^D
	printf("The number of words is %d\n", cntr_words);
	printf("The number of chars is %d\n", cntr_chars);
	// it will cunt ^D if the first char is not ^D
	printf("The number of new lines is %d\n", cntr_ls);
	// ^D + Enter to quit the app, resonable to star from 0.

	return 0;
}