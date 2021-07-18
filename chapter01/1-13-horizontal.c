/*
 * Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#include <stdio.h>

#define MAXHIST  15
#define MAXWORD  15
#define IN        1
#define OUT       0

int main(void)
{
	int c, i, charCount, state;
	int len;
	int maxvalue;
	int overflow;
	int wordlength[MAXWORD];

	state = OUT;
	charCount = overflow = maxvalue = 0;

	// initial wordlength as zero array
	for (i = 0; i < MAXWORD; i++)
		wordlength[i] = 0;
	// count wordlength
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
			if (charCount > 0)
			{
				if (charCount < MAXWORD)
					++wordlength[charCount];
				else
					++overflow;
			}
			charCount = 0;
		}
		else if (state == OUT)
		{
			state = IN;
			charCount = 1;
		}
		else
			++charCount;
	}

	// find out the max value
	for (i = 1; i < MAXWORD; ++i)
		if (wordlength[i] > maxvalue)
			maxvalue = wordlength[i];

	// draw
	for (i = 1; i < MAXWORD; ++i)
	{
		printf("%5d - %5d : ", i, wordlength[i]);
		if (wordlength[i] > 0)
		{
			if ((len = wordlength[i] * MAXHIST / maxvalue) <= 0)
			       len = 1;
		}	
		else
			len = 0;
		// draw current hist bar
		while (len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (overflow > 0)
		printf("\nThere are %d words >= %d\n", overflow, MAXWORD);
}
