/* Exercise 1-13 in K&R
 * Version 1
 * Benjamin Sadler, 02/04/20
 *
 * Exercise prompt:
 * "Write a program to print a histogram of the lengths of words in its
 * input.  It is easy to draw the histogram with the bars horizontal; a
 * vertical orientaion is more challenging."
 *
 */

#include <stdio.h>

	/* the symbolic constant 'max' is the maximum number of 
	 * counts in the histogram:
	 */

#define max 15

main()
{
	int c, flag, i, j, nchar;
	int nlength[20];

	for (i = 0; i < 20; ++i)
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

	/* print vertically-oriented histogram of characters/word:
	 */

	printf("%s\n", "histogram of numbers of characters per word in input file");
	
	for (j = max-1; j > 0; --j) {
		for (i = 0; i < 20; ++i) { 
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
