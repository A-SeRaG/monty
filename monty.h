#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*operations1.c*/
void R_file(FILE *fd);
void O_file(char *file_name);
int S_line(char *buffer, int LN, int format);
void F_function(char *opcode, char *value, int ln, int format);
void C_fun(op_func func, char *op, char *val, int ln, int format);

/*operations2.c*/
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln);
void mul_nodes(stack_t **stack, unsigned int LN);
void mod_nodes(stack_t **stack, unsigned int LN);

/*functions1.c*/
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln);
void _pop(stack_t **stack, unsigned int LN);
void print_stack(stack_t **stack, unsigned int LN);
void print_top(stack_t **stack, unsigned int LN);

/*functions2.c*/
void nop(stack_t **stack, unsigned int LN);
void add_nodes(stack_t **stack, unsigned int LN);
void sub_nodes(stack_t **stack, unsigned int LN);
void div_nodes(stack_t **stack, unsigned int LN);
void swap_nodes(stack_t **stack, unsigned int LN);

/*advanced_s.c*/
void print_c(stack_t **stack, unsigned int ln);
void print_s(stack_t **stack, __attribute__((unused)) unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln);
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln);

/*error_massage.c*/
void errors1(int, ...);
void errors2(int, ...);

/*main.c*/
stack_t *C_node(int n);
void free_nodes(void);
void F_nodes(void);

#endif

