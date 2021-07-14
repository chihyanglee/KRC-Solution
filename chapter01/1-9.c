/*
 * Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

#define NONBLANK 'A'
int main(void)
{
	int c, lastcharacter = NONBLANK;

	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (lastcharacter != ' ')
				putchar(c);
		lastcharacter = c;
	}
}
