#include "monty.h"

/**
 * errors - Prints error messages determined by its error number.
 * @err_num: The error number are the following:
 * (1) -> The user does not give any file or more than one file to the program.
 * (2) -> The file provided is not a file that can be opened or read.
 * (3) -> The file provided contains an invalid instruction.
 * (4) -> When the program is unable to malloc more memory.
 * (5) -> When the parameter passed to the instruction "push" is not an int.
 */

void errors1(int err_num, ...)
{
	va_list arg;
	char *op;
	int LN;

	va_start(arg, err_num);
	switch (err_num)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
		break;
	case 3:
		LN = va_arg(arg, int);
		op = va_arg(arg, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", LN, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
		break;
	}
	F_nodes();
	exit(EXIT_FAILURE);
}
/**
 * errors - Prints error messages determined by its error number.
 * @err_num: The error number are the following:
 * (6) -> When the stack it empty for pint.
 * (7) -> When the stack it empty for pop.
 * (8) -> When stack is too short for operation.
 * (9) -> Division by zero.
 * (10) -> The number inside a node is out of range of ASCII nums.
 * (11) -> The stack is empty.
 */
void errors2(int err_num, ...)
{
	va_list arg;
	char *op;
	int LN;
	LN = va_arg(arg, unsigned int);
	op = va_arg(arg, char *);

	va_start(arg, err_num);
	switch (err_num)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
		break;
	case 8:
		fprintf(stderr, "L%d: can't %s, stack too short\n", LN, op);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n", LN);
		break;
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", LN);
		break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", LN);
		break;
	default:
		break;
	}
	F_nodes();
	exit(EXIT_FAILURE);
}

