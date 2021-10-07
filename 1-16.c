/* Exercise 1-16 in C Programming by Kernighan and Ritchie
*  Benjamin Sadler, 02/05/20
*
*  Exercise Prompt: "Revise the main routine of the longest-line 
*  program so it will correctly print the length of arbitrarily 
*  long input lines, and as much as possible of the text."
*
*  */

#include <stdio.h>

#define MAXLINE 10

int getline2(char line[], int maxline);
void copy(char to[], char from[], int maxline);

main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = getline2(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line, MAXLINE);
			}
	if (max > 0) 
		printf("%d %s\n", max, longest);
	return 0;
}

int getline2(char s[], int lim)
{
	int c, i;	

	for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim-1) 
			s[i] = c;
		if (i >= lim-1)
			;
	}

	if (c == '\n' && i < lim-1) {
		s[i] = c;
		++i; 
	}	
	if (c == '\n' && i >= lim)
		++i;

	if (i <= lim-1)
		s[i] = '\0';
	else
		s[lim-1] = '\0';
	
	return i;
}

void copy(char to[], char from[], int lim)
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0' && i < lim)
		++i;
}

