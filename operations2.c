#include "monty.h"

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int LN)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "mul");
	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @LN: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int LN)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		errors2(8, LN, "mod");
	if ((*stack)->n == 0)
		errors2(9, LN);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

