/* Excercise 1-22 in K&R
*  Benjamin Sadler, 02/11/20
*
*  Exercise Prompt: "Write a program to "fold" long 
*  input lines into two or more shorter lines after 
*  the last non-blank character that occurs before 
*  the n -th column of input. Make sure your program 
*  does something intelligent with very long lines, and 
*  if there are no blanks or tabs before the specified 
*  column."
*
* */

#include <stdio.h>
#define MAXLINE 1000
#define nt_space 8 
#define line_lim 50
#define line_lim_sig 8

int getline4(char line[], int maxline);
void printline(char line[], int maxline);
void reverse(char line[], char r_line[], int maxline);
void detab(char line[], char dt_line[], int maxline);
void entab(char line[], char r_line[], int maxline);
void foldline(char line[], char line_1[], char line_2i[], int maxline);

main()
{

	int len;
	char line[MAXLINE];
	char r_line[MAXLINE];
	while ((len = getline4(line, MAXLINE)) >= 0) 
		;
	
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


int getline4(char s[], int lim)
{
	int c, i, j, k, l;

	char line_buffer[MAXLINE];

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

	if (i > line_lim) {
		j = k = 0;
		line_search:	
		while (k < line_lim && j <= i) {
			line_buffer[k] = s[j];
			++j;
			++k;	
		}
		if (k == line_lim) {
			for (l = 0; line_buffer[k-l] != ' ' && l <= line_lim_sig; ++l)
			       ;
			if (l > line_lim_sig) {
				line_buffer[k-1] = '-';
				line_buffer[k] = '\n';
				line_buffer[k+1] = '\0';	
				printline(line_buffer, lim);
				--j;
				k = 0;
				goto line_search;
			}
			else {
				line_buffer[k-l] = '\n';
				line_buffer[k-l+1] = '\0';
				printline(line_buffer, lim);
				j = j-l+1;
				k = 0;
				goto line_search;
			}	
		}
		else 
			printline(line_buffer, lim);
	}	
	else if (i < line_lim && i > 0)  	
		printline(s, lim);	

	return i;
}

void entab(char s[], char r[], int lim)
{
	
	int i, j, k;
	i = 0;
	j = 0;

	while (s[i] != '\0' && i < lim-1) {

		if (s[i] == ' ') {
 			for (k=0; s[i+k] == ' ' && k < nt_space; ++k)
				;
			if (k == nt_space) {
				r[j] = '\t';
				i = i+nt_space;
				++j;	
			}
			else {
				r[j] = s[i];
				++i;
				++j;
			}
		}

		else {
			r[j] = s[i];
			++i;
			++j;
		}
	}	
	
	r[j] = '\0';

}

void detab(char s[], char r[], int lim)
{

	int i,j,k;
	i = 0;
	j = 0;

	while (s[i] != '\0' && i < lim-1) {

		if (s[i] == '\t') { 
			for (k=0; k < nt_space; ++k)
				r[j+k] = ' ';
			j = j+nt_space-1;
		}

		else
			r[j] = s[i];

		++j;
		++i;
	}

	r[j] = '\0';

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
