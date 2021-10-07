/* Exercise 1-24 in K&R
 * 
 * Benjamin Sadler, v2 10/07/21
 *
 * v2 corrects some errors related to the stack index running negative 
 * (more closing chars than opening chars).
 *
 * Exercise prompt:
 * "Write a program to check a C program for rudimentary syntax errors
 * like unbalanced parentheses, brackets, and braces.  Don't forget about
 * quotes, both single and double, escape sequences, and comments.  (This
 * program is hard if you do it in full generality.)"
 *
 */

#include <stdio.h>

main()
{
	int c, c_old, escape_flag, i, j, k, stack[1000], state;

	int error_line[1000], error_column[1000];

	int esc_line, esc_column;

	int line_curr, col_curr, stack_column[1000], stack_line[1000];

	c_old = '\0';
	escape_flag = 0;
	state = 0;
	i = j = 0;
	line_curr = col_curr = 0;
	esc_line = esc_column = 0;

	/* state key:
	 * state = 0 -> default
	 * state = 1 -> comment
	 * state = 2 -> char
	 * state = 3 -> string
	 * 
	 * index key:
	 * i -> stack index
	 * j -> errorstack index
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

		/* check if entering comment, char constant, or 
		 * string constant from default mode:
		 */

		if (state == 0 && c == '*' && c_old == '/'){
                        state = 1;
			esc_column = col_curr;
			esc_line = line_curr;
		}
                else if (state == 0 && c == '\''){
                        state = 2;
			esc_column = col_curr;
			esc_line = line_curr;
		}
                else if (state == 0 && c == '"'){
                        state = 3;
			esc_column = col_curr;
			esc_line = line_curr;
		}

		/* if not in default mode, check to see if returning
                 * to default mode, ensuring end quote is not escaped:
                 */

                else if (state == 1 && c == '/' && c_old == '*'){ 
                        state = 0;
			esc_line = 0;
			esc_column = 0;
		}
                else if (state == 2 && c == '\'' && escape_flag == 0){
                        state = 0;
			esc_line = 0;
			esc_column = 0;
		}
                else if (state == 3 && c == '"' && escape_flag == 0){
                        state = 0;
			esc_line = 0;
			esc_column = 0;
		}

		/* if in default mode, place opening parentheses and 
		 * brackets on stack, and remove stack entries for 
		 * closed chars. 
		 *
		 * record any anomalies on errorstack. */

		/* stack values key:
		 *
		 * open '(' -> 0
		 * open '[' -> 1
		 * open '{' -> 2
		 *
		 * check for opening or closing groups if in default
		 * mode:
		 */

		else if (state == 0 && c == '(') {
			++i;
			stack[i] = 0;
			stack_line[i] = line_curr;
			stack_column[i] = col_curr;
		}
		else if (state == 0 && c == '[') {
			++i;
			stack[i] = 1;
			stack_line[i] = line_curr;
			stack_column[i] = col_curr;
		}
		else if (state == 0 && c == '{') {
			++i;
			stack[i] = 2;
			stack_line[i] = line_curr;
			stack_column[i] = col_curr;
		}

		/* check for closing characters, deleting stack 
		 * elements if approved - if unapproved closing 
		 * occurs, update errorstack:
		 */

		else if (state == 0 && c == ')') {
			if (stack[i] == 0 && i != 0)
			       --i;
			else {
				error_line[j] = line_curr;
				error_column[j] = col_curr;
				++j;
			}		
		}		
		else if (state == 0 && c == ']') {
                        if (stack[i] == 1 && i != 0)
                               --i;
                        else {
                                error_line[j] = line_curr;
				error_column[j] = col_curr;
                                ++j;
                        }
                }
		else if (state == 0 && c == '}') {
                        if (stack[i] == 2 && i != 0)
                               --i;
                        else {
                                error_line[j] = line_curr;
				error_column[j] = col_curr;
                                ++j;
                        }
                }

		else if (state == 0 && i == 0 && (c == ')' || c == ']' || c == '}')) {
			error_line[j] = line_curr;
			error_column[j] = col_curr;
			++j;
		}

		/* if newline is encountered, increment line_curr and reset
		 * col_curr to zero; otherwise, increment col_cur:
		 */

		if (c == '\n') {
			++line_curr;
			col_curr = 0;
		}
		else
			++col_curr;

		c_old = c;

	}

	/* output errors for any open chars left on stack, badly
	 * closed chars, or unescaped chars:
 	 */

	// diagnostics
	//printf("%s %d\n", "stack index:", i);
	//printf("%s %d\n", "error index:", j);

	if (i > 0) {
		printf("\n");
		k = 1;
		printf("Unclosed Characters\n");
		printf("Line / Column:\n");
		while (k <= i) { 
			printf("%d      %d\n", stack_line[k]+1, stack_column[k]+1); 
			++k;
		}
	}

	if (j > 0) {
		printf("\n");
		k = 0;
		printf("Closing Errors\n");
		printf("Line / Column:\n");
		while (k < j) {
			printf("%d      %d\n", error_line[k]+1, error_column[k]+1);
			++k;
		}
	}

	if (esc_line != 0 || esc_column != 0) {
		printf("\n");
		printf("Unclosed Quote/Comment Escape Characters\n");
		printf("Line / Column:\n");
		printf("%d      %d\n", esc_line+1, esc_column+1);
	}

	if (i == 0 && j == 0 && esc_line == 0 && esc_column ==0){
		printf("\n");
		printf("no rudimentary syntax errors (unbalanced parentheses, brackets, or braces), nor unclosed quotes or comments found in document!\n");
	}

	printf("\n");

}
