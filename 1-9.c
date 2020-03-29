/* Exercise 1-9 in K&R
 * Version 1
 * Benjamin Sadler, 02/01/20
 *
 * Exercise prompt:
 * "Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank."
 *
 */

#include <stdio.h>

main()

{
	int c,old_c;

	old_c = '\x00';

	while ((c = getchar()) != EOF) {

		if(old_c != ' ' || c != ' ')
			putchar(c);
		if(c == ' ')
			old_c = ' ';
		if(c != ' ')
			old_c = '\x00';
	}

} 
		
