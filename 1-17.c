/* Excercise 1-17 in K&R
*  Benjamin Sadler, 02/06/20
*
*  Exercise Prompt: "Write a program to print all input lines 
*  that are longer than 80 characters."
*
* */

#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int maxline);
void printline(char line[], int maxline);

main()
{

	int len;
	char line[MAXLINE];
	while ((len = getline2(line, MAXLINE)) > 0) {
		if(len > 80)	
			printline(line, MAXLINE);
		printf("%s %d\n", "line length:", len);
	}
	return 0;
}

int getline2(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void printline(char s[], int lim)
{
	int i;
	i = 0;
	
	while (s[i] != '\0' && i < lim) {
		putchar(s[i]);
		i++;
	}
}
