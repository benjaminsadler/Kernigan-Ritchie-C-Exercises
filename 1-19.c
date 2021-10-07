/* Excercise 1-19 in K&R
*  Benjamin Sadler, 02/06/20
*
*  Exercise Prompt: "Write a function reverse(s) that reverses 
*  the character string s . Use it to write a program that 
*  reverses its input a line at a time."
*
* */

#include <stdio.h>
#define MAXLINE 1000

int getline3(char line[], int maxline);
void printline(char line[], int maxline);
void reverse(char line[], char r_line[], int maxline);

main()
{

	int len;
	char line[MAXLINE];
	char r_line[MAXLINE];
	while ((len = getline3(line, MAXLINE)) >= 0) {
		if(len > 1) {	
			reverse(line, r_line, MAXLINE);
			printline(r_line, MAXLINE);
		}
		printf("%s %d\n", "line length:", len);
	}
	return 0;
}

void reverse(char s[], char r[], int lim)
{
	int i, j;

	i = 0;
	while (s[i] != '\0')
		++i;

	j = 0;
	while (i > 1) {
		r[j] = s[i-2];
		--i;
		++j;
	}	
	
	r[j] = '\n';
	r[j+1] = '\0';
}

int getline3(char s[], int lim)
{
	int c, i, j;
	
	for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
	
		for (j = i; s[j-1] == '\t' || s[j-1] == ' '; --j) 
			;
		if (j != i) {
			s[j] = '\n';
			s[j+1] = '\0';
			i = j+1;
		}
		if (j == i) {
			++i;	
			s[i] = '\0';	
		}	
	}

	else if (c == EOF) 
		i = -1;
	else if (i = lim-1)
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
