#include "monty.h"

/**
 * open_file - ...
 * @file_name: ...
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);
	read_file(fd);
	fclose(fd);
}
/**
 * read_file - ...
 * @fd: ...
 */
void read_file(FILE *fd)
{
	int l_num, f = 0;
	char *b = NULL;
	size_t len = 0;

	for (l_num = 1; getline(&b, &len, fd) != -1; l_num++)
	{
		f = parse_line(b, l_num, f);
	}
	free(b);
}

/**
 * parse_line - ..
 * @b: ...
 * @l_num: ...
 * @f: ...
 * Return: ...
 */
int parse_line(char *b, int l_num, int f)
{
	char *op, *v;
	const char *d = "\n";

	if (b == NULL)
		err(4);
	op = strtok(b, d);
	if (op == NULL)
		return (f);
	v = strtok(NULL, d);
	if (strcmp(op, "stack") == 0)
		return (0);
	if (strcmp(op, "queue") == 0)
		return (1);
	find_func(op, v, l_num, f);
	return (f);
}
/**
 * find_func - ...
 * @op: ...
 * @v: ...
 * @ln: ...
 * @f: ...
 */
void find_func(char *op, char *v, int ln, int f)
{
	int i, flag;
	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(op, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, op, v, ln, f);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, op);
}

/**
 * call_fun - ..
 * @func: ..
 * @op: ..
 * @val: ...
 * @ln: ...
 * @f: ..
 */
void call_fun(op_func func, char *op, char *val, int ln, int f)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val++;
			flag--;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (f == 0)
			func(&node, ln);
		if (f == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
