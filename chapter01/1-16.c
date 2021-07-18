/*
 * Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as
 * possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

void copy(char to[], char from[]);

int main(void)
{
	int len, max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = getline(line, MAXLINE)) > 0)
	{
		printf("%3d: %s", len, line);
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
		printf("\nLongest line: %s", longest);
}

int getline(char s[], int limit)
{
	int c, i, j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < limit - 2)
		{
			s[j] = c;
			++j;
		}
	}

	if (c == '\n')
	{
		s[j] = c;
		++j;
		++i;
	}

	s[j] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
