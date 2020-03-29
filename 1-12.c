/* Exercise 1-12 in K&R
 * Version 1
 * Benjamin Sadler, 02/03/20
 *
 * Exercise prompt:
 * "Write a program that prints its input one word per line."
 *
 */

#include <stdio.h>

main()
{

	int c, flag;

	flag = 0;

	/* flag key:
	 * flag = 0 -> in a word
	 * flag = 1 -> out of a word
	 */

	while ((c = getchar()) != EOF) {
		if (c == ' ' && flag == 0) {
			flag = 1;
			putchar('\n');
		}
		else if (c == ' ' && flag == 1)
			;
		else if (c == '\n' && flag == 0) {
			flag = 1;
			putchar(c);
			}
		else if (c == '\n' && flag == 1) 
			;
		else if (c == '\t' || c == '\b')
			flag = 1;
		else { 
			flag = 0;	
			putchar(c);
		}	
	}
}	

