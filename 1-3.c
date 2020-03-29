/* Exercise 1-3 in K&R
 * Version 1
 * Benjamin Sadler, 01/30/20
 *
 * Exercise prompt: 
 * "Modify the temperature conversion program to print a heading above
 * the table."
 *
 */

#include <stdio.h>

main()
	{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 10;

	printf("Temperature Conversion Chart\n");
	printf("%4s%s%7s\n", "Fahr","  ", "Celsius");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f%3s%5.1f\n", fahr,"   ", celsius);
		fahr = fahr + step;
	}
}

