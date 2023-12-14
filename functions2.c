#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */

void nop(stack_t **stack, unsigned int LN)
{
	(void)stack;
	(void)LN;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int LN)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - substract the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int LN)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "sub");
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int LN)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "div");
	if ((*stack)->n == 0)
		errors2(9, LN);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */

void swap_nodes(stack_t **stack, unsigned int LN)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

