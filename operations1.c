#include "monty.h"

/**
 * R_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void R_file(FILE *fd)
{
	int LN, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (LN = 1; getline(&buffer, &len, fd) != -1; LN++)
		format = S_line(buffer, LN, format);
	free(buffer);
}

/**
 * O_file - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void O_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		errors1(2, file_name);
	R_file(fd);
	fclose(fd);
}

/**
 * S_line - Separates each line to determine which function to call
 * @buffer: line from the file
 * @LN: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: 0 if stack. 1 if queue.
 */

int S_line(char *buffer, int LN, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		errors1(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	F_function(opcode, value, LN, format);
	return (format);
}

/**
 * F_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void F_function(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t L_function[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", _pop},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_c},
		{"pstr", print_s},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; L_function[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, L_function[i].opcode) == 0)
		{
			C_fun(L_function[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors1(3, ln, opcode);
}

/**
 * C_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void C_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			errors1(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errors1(5, ln);
		}
		node = C_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

