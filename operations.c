#include "monty.h"
/**
 * push - pushes a number onto the stack
 * @num: number to push
 *
 * Return: void
 */
void push(int num)
{
	stack_t *new;

	if (first == NULL)
	{
		first = malloc(sizeof(stack_t));
		if (!first)
			error_malloc();
		first->n = num;
		first->prev = NULL;
		first->next = NULL;
		global.the_first = first;
	}
	else
	{
		new = malloc(sizeof(stack_t));
		if (!new)
			error_malloc();
		new->n = num;
		new->prev = first;
		new->next = NULL;
		first->next = new;
		first = new;
	}
}

/**
 * pall - prints everything in stack
 *
 * Return: void
 */
void pall(void)
{
	stack_t *temp;

	temp = global.the_first;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the top most element of the stack
 */

void pint(void)
{
	printf("%d\n", first->n);
}
