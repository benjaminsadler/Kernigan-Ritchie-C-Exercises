/* Exercise 1-14 in C Programming by Kernighan & Ritchie
 * Benjamin Sadler, 02/05/20
 * Version 2 - 03/29/20 - added dynamic histogram range
 *
 * USAGE:
 * cat <input file> | <compiled executable>
 *
 * LIMITS:
 * This program only histograms the letters 'a-z' and 'A-Z'.
 * 
 * Exercise prompt:
 * "Write a program to print a histogram of the frequencies of different
 * characters in its input."
 *
 */

#include <stdio.h>

main()
{

	int c, i, j, max; 			/* initiallize variables */
	int noccur[52];

	for (i = 0; i < 52; ++i)
		noccur[i] = 0;

	while ((c = getchar()) != EOF) {        /* bin characters, a-z and A-Z */
		if (c >= 'A' && c <= 'Z') 
			++noccur[c - 'A'];
		if (c >= 'a' && c <= 'z')
			++noccur[c - 'A' - 6];	
	}
	
	j = 0;					/* determine histogram range, add */
	for (i = 0; i < 52; ++i)		/* two-line buffer */
		if (noccur[i] > j)
			j = noccur[i];
	max = j + 2;

	for (i = 0; i < 52; ++i) {              /* diagnostic output */
		if (i >= 0 && i < 26) 
			putchar('A' + i);
		else
			putchar('A' + 6 + i);
		printf(" - %d\n", noccur[i]);
		}	

	for (j = max-1; j > 0; --j) {           /* histogram results */
		for (i = 0; i < 52; ++i) { 
			if (noccur[i] >= j)	
				printf("%s", "x");
			else
				printf("%s", " ");
			}
			printf("\n");
		}

	for (i = 0; i < 52; ++i) {             /* output histogram domain labels */ 
		if (i >= 0 && i < 26)
			putchar('A' + i);
		else 
			putchar('A' + 6 + i);	
		}
	printf("\n");

}	
