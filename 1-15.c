/* Excercise 1-15 in C Programming by Kernighan and Ritchie
*  Benjamin Sadler, 02/05/20
*
*  Exercise Prompt: "Rewrite the temperature conversion program 
*  of Section 1.2 to use a function for conversion."
*
/  */

#include <stdio.h>

int convert_celsius(int);

main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = -40;
	upper = 300;
	step = 10;

	printf("%s\n", "Fahrenheit     Celsius");
	for (fahr = lower; fahr <= upper; fahr = fahr + step) {

		celsius = convert_celsius(fahr);

		printf("%3d            %3d\n", fahr, celsius);

		}
	return 0;
}

int convert_celsius(int fahr) {

	int celsius;

	celsius = 5 * (fahr - 32) / 9;

	return celsius;
}
