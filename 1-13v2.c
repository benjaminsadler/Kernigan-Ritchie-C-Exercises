/* Exercise 1-13 in K&R
 * Version 2 - added dynamic histogram range 
 * Benjamin Sadler, 03/29/20
 *
 * Exercise prompt:
 * "Write a program to print a histogram of the lengths of words in its
 * input.  It is easy to draw the histogram with the bars horizontal; a
 * vertical orientaion is more challenging."
 *
 */

#include <stdio.h>

	/* the symbolic constant 'max' is the maximum number of 
	 * characters allowed in a word:
	 */

#define max 20 

main()
{
	int c, flag, i, j, nchar;
	int nlength[max];

	for (i = 0; i < max; ++i)
		nlength[i] = 0;

	nchar = 0; 
	flag = 0;

	/* count the characters in each word:
	 */

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '.' || c == '\n' || c == '\t' ||
			c == '?' || c == ',' || c == '\b' || c == '!')  
			flag = 1;
		else {
			++nchar;
			flag = 0;
			}
		if (flag == 1) {
			if (nchar != 0) 
				++nlength[nchar];
			nchar = 0;
			}
	}

	/* determine the max bin height (reusing variable 'nchar' to flag
	 * the magnitude of largest bin, then pad it by two lines), and then  
	 * print vertically-oriented histogram of characters/word:
	 */

	nchar = 0;
	for (j = 0; j < max; ++j)  
		if (nlength[j] > nchar) 
			nchar = nlength[j];

	nchar = nchar + 2;

	printf("%s\n", "histogram of numbers of characters per word in input file");
	
	for (j = nchar-1; j > 0; --j) {
		for (i = 0; i < max; ++i) { 
			if (nlength[i] >= j)	
				printf("%s", "x");
			else
				printf("%s", " ");
		}
			printf("\n");
	}

	for (i = 0; i < 10; ++i) 
		printf("%d",i);
	printf("\n");
	printf("%s\n", "(numbers of letters per word)"); 

}	
