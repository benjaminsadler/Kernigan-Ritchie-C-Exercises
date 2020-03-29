/* Exercise 1-7 in K&R
 * Version 1
 * Benjamin Sadler, 01/31/20
 *
 * Exercise prompt:
 * "Write a program to print the value of EOF."
 *
 */

#include <stdio.h>

main()
{
	int c;
	int d;
	while ((c = getchar()) != EOF)
		putchar(c);

	/* print the EOF character once when loop exits */
	printf("%d", c);
	printf("\n");	
}
