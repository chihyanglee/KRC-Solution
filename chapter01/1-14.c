/*
 * Write a program to print a histogram of the frequencies of different characters in its input.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXHIST 15
#define MAXCHAR 128

int main(void)
{
	int c;
	int i, len, maxvalue;
	int charCounter[MAXCHAR];

	i = len = maxvalue = 0;

	// initialize charCounter
	for (i = 0; i < MAXCHAR; ++i)
		charCounter[i] = 0;

	while ((c = getchar()) != EOF)
		if (c < MAXCHAR)
			++charCounter[c];

	// find out maxvalue
	for (i = 1; i < MAXCHAR; ++i)
		if (charCounter[i] > maxvalue)
			maxvalue = charCounter[i];

	printf("maxvalue: %d\n", maxvalue);

	for (i = 1; i < MAXCHAR; ++i)
	{
		if (isprint(i))
			printf("%5d - %c - %5d : ", i, i, charCounter[i]);
		else
			printf("%5d -  - %5d : ", i, charCounter[i]);
		if (charCounter[i] > 0)
		{
			if ((len = charCounter[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;

		while (len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}
