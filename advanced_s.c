#include "monty.h"

/**
 * print_c - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of the opcode
 */
void print_c(stack_t **stack, unsigned int ln)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		errors2(11, ln);
	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		errors2(10, ln);
	printf("%c\n", ascii);
}

/**
 * print_s - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of the opcode
 */
void print_s(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	int ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		ascii = temp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of the opcode
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: line number of the opcode
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

