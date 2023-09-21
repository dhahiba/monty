#include "monty.h"
/**
 * add_to_stack - ...
 * @new_node: ...
 * @ln: ..
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
/**
 * print_stack - ...
 * @stack: ..
 * @l_num: ..
 */
void print_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pop_top - ...
 * @stack: ..
 * @l_num: ...
 */

void pop_top(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, l_num);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * print_top - ..
 * @stack: ...
 * @l_num: ...
 */

void print_top(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, l_num);
	printf("%d\n", (*stack)->n);
}
