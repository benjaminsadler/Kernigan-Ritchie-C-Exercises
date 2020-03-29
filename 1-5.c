/* Exercise 1-5 in K&R
 * Version 1
 * Benjamin Sadler, 01/30/20
 *
 * Exercise prompt:
 * "Modify the temperature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0."
 *
 */

#include <stdio.h>

/* print Fahrenheit to Celsius table, backwards */

main()
	{
	int fahr;

	for(fahr = 300; fahr >=0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

