/* Exercise 1-23 in K&R
 * Version 2
 * Benjamin Sadler and Sean Barton, 03/25/20
 * 
 * Exercise prompt:
 * "Write a program to remove all comments from a C program.  Don't forget to handle quoted strings and
 * character constants properly.  C comments do not nest."
 *
 */ 
 
#include <stdio.h>

main()
{
	int state, c, c_old1, c_old2, j;

	c_old1 = c_old2 = '\0';
	state = 0;
	j = 0;

	/* state key:
	 *
	 * state = 0 -> default
	 * state = 1 -> comment
	 * state = 2 -> char
	 * state = 3 -> string
	 */

	while ((c = getchar()) != EOF) {

		/* begin in default (state = 0) mode; check if entering comment,
		 * char constant, or string constant: 
		 */

		if (c == '*' && c_old1 == '/' && state == 0)  
			state = 1;
		else if (c == '\'' && c_old1 != '\\' && c_old1 != '\'' && state == 0) 
			state = 2;
		else if (c == '"' && state == 0) 
			state = 3;

		/* if not in default mode, check to see if returning
		 * to default mode:
		 */

		else if (state == 1 && c == '/' && c_old1 == '*') {
			state = 0;
			j = 2;
		}
		else if (state == 2 && ((c == '\'' && c_old1 != '\\') || 
			(c == '\'' && c_old1 == '\\' && c_old2 == '\\'))) 
			state = 0;
		else if (state == 3 && c == '"' && c_old1 != '\\' && c_old1 != '\'') 
			state = 0;

		/* if coming out of comment, or already inside char or string
		 * constant, output all characters:
		 */

		if (state == 0 || state == 2 || state == 3)
			if (j)
				--j;
			else
				putchar(c_old1);

		/* update c_old's */

		c_old1 = c;
		c_old2 = c_old1;

	}

}
