/* Exercise 1-23 in K&R
 * Version 3 
 * Benjamin Sadler and Sean Barton, 03/29/20
 * 
 * Exercise prompt:
 * "Write a program to remove all comments from a C program.  Don't forget to handle quoted
 * strings and character constants properly.  C comments do not nest."
 *
 */ 
 
#include <stdio.h>

main()
{
	int c, c_old, escape_flag, j, state;

	c_old = '\0';
	escape_flag = 0;
	j = 0;
	state = 0;

	/* state key:
	 *
	 * state = 0 -> default
	 * state = 1 -> comment
	 * state = 2 -> char
	 * state = 3 -> string
	 */

	while ((c = getchar()) != EOF) {

		/* set escape flag if needed:
		 */

		if (c_old == '\\' && escape_flag == 0)
			escape_flag = 1;
		else if (c_old == '\\' && escape_flag == 1)
			escape_flag = 0;
		else
			escape_flag = 0;

		/* check if entering comment, char constant, or string
		 * constant from default mode: 
		 */

		if (state == 0 && c == '*' && c_old == '/')   
			state = 1;
		else if (state == 0 && c == '\'') 
			state = 2;
		else if (state == 0 && c == '"') 
			state = 3;

		/* if not in default mode, check to see if returning
		 * to default mode, ensuring end quote is not escaped:
		 */

		else if (state == 1 && c == '/' && c_old == '*') { 
			state = 0;
			j = 2;
		}
		else if (state == 2 && c == '\'' && escape_flag == 0)  
			state = 0;
		else if (state == 3 && c == '"' && escape_flag == 0) 
			state = 0;
		
		/* if in default, char, or string mode, output all 
		 * characters, using 2-char 'j' buffer if recently
		 * exiting comment mode:
		 */

		if (state == 0 || state == 2 || state == 3)
			if (j)
				--j;
			else
				putchar(c_old);

		/* update c_old */

		c_old = c;
	
	}

}
