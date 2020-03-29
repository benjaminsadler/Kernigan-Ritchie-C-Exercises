/* Exercise 1-4 in K&R
 * Version 1
 * Benjamin Sadler, 01/30/20
 *
 * Exercise prompt:
 * "Write a program to print the corresponding Celsius to Fahrenheit table."
 *
 */

#include <stdio.h>

main()
	{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = -20;
	upper = 150;
	step = 10;

	printf("Temperature Conversion Chart\n");
	printf("%7s\t%s\n", "Celsius", "Fahr");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0)*celsius + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}

