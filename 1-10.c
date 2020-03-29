/* Exercise 1-10 in K&R
 * Version 1
 * Benjamin Sadler, 02/01/20
 *
 * Exercise prompt:
 * "Write a program to copy its input to its output, replacing each tab
 * by \t, each backspace by \b, and each backslash by \\.  This makes
 * tabs and backspaces visible in an unambiguous way."
 *
 */

#include <stdio.h>

main()

{

	int c;

	while ((c = getchar()) != EOF) {

		if (c != '\t' && c != '\b' && c != '\\')
			putchar(c);
		if (c == '\t') 
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");

	}
}
