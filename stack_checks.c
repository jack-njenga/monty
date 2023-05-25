#include "monty.h"
/**
 * len_stack - give the number of elements on stack
 *
 * Return: number of nodes
 */
int len_stack(void)
{
	size_t i = 0;
	stack_t *top = first;

	while (top != NULL)
	{
		i++;
		top = top->next;
	}
	return (i);
}
