/* Exercise 1-8 in K&R
 * Version 1
 * Benjamin Sadler, 02/01/20
 *
 * Exercise prompt:
 * "Write a program to count blanks, tabs, and newlines."
 *
 */

#include <stdio.h>

main()

{

	int c;
	long n_blank, n_tab, n_newline;

	n_blank = 0;
	n_tab = 0;
	n_newline = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') 
			++n_blank;
		if (c == '\t')
			++n_tab;
		if (c == '\n')
			++n_newline;
		}

		printf("%s %ld\n", "number of blanks: ", n_blank);
		printf("%s %ld\n", "number of tabs: ", n_tab);
		printf("%s %ld\n", "number of newlines: ", n_newline); 

}
 
