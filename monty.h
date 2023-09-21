#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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
void open_file(char *file_name);
int parse_line(char *b, int l_num, int f);
void read_file(FILE *fd);
void find_func(char *op, char *v, int ln, int f);

stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int l_num);
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln);
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln);

void call_fun(op_func func, char *op, char *val, int ln, int f);

void print_top(stack_t **stack, unsigned int l_num);
void pop_top(stack_t **stack, unsigned int l_num);
void nop(stack_t **stack, unsigned int l_num);
void swap_nodes(stack_t **stack, unsigned int l_num);

void add_nodes(stack_t **stack, unsigned int l_num);
void sub_nodes(stack_t **stack, unsigned int l_num);
void div_nodes(stack_t **stack, unsigned int l_num);
void mul_nodes(stack_t **stack, unsigned int l_num);
void mod_nodes(stack_t **stack, unsigned int l_num);


void print_char(stack_t **stack, unsigned int l_num);
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln);
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln);

void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln);
#endif
