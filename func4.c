#include "monty.h"

/**
 * print_char - ...
 * @stack: ...
 * @l_num: ..
 */

void print_char(stack_t **stack, unsigned int l_num)
{
	int i;

	if (stack == NULL || *stack == NULL)
		string_err(11, l_num);
	i = (*stack)->n;
	if (i < 0 || i > 127)
		string_err(10, l_num);
	printf("%c\n", i);
}

/**
 * print_str - ..
 * @stack: ...
 * @ln: ...
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int i;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		i = tmp->n;
		if (i <= 0 || i > 127)
			break;
		printf("%c", i);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * rotl - ..
 * @stack: ...
 * @ln: ...
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
/**
 * rotr - ..
 * @stack: ...
 * @ln: ..
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
