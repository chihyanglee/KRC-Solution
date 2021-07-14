/*
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

int main(void)
{
	int c, flag = 1;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (flag)
			{
				flag = 0;
				putchar('\n');
			}
		}
		else
		{
			flag = 1;
			putchar(c);
		}
	}
}
