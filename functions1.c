#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * _pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */

void _pop(stack_t **stack, unsigned int LN)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		errors2(7, LN);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_stack - print the node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int LN)
{
	stack_t *temp;

	(void)LN;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int LN)
{
	if (stack == NULL || *stack == NULL)
		errors2(6, LN);
	printf("%d\n", (*stack)->n);
}

