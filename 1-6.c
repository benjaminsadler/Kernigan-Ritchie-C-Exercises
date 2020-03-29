/* Exercise 1-6 in K&R
 * Version 1
 * Benjamin Sadler, 01/31/20
 *
 * Exercise prompt:
 * "Verify that the expression getchar() != EOF is 0 or 1."
 *
 * Usage: this program determines whether the first character of the 
 * input file is 'EOF' or not.  Pipe in a non-empty file to receive an 
 * output of '1', or pipe in an empty file to receive an output of '0'.
 *
 */

#include <stdio.h>

main()
{
	int c;
	c = getchar() != EOF;
	printf("%d", c);
	printf("\n");	
}
