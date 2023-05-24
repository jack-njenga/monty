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
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		first->n = num;
		first->prev = NULL;
		first->next = NULL;
	}
	else
	{
		new = malloc(sizeof(stack_t));
		if (!new)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
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

	temp = first;
	if (temp == NULL)
	{
		/*fprintf(stderr, "stack underflow\n");*/
		/*exit(EXIT_FAILURE);*/
	}
	else
	{
		while (temp->prev != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
		if (temp->prev == NULL)
		{
			printf("%d\n", temp->n);
		}
	}
}

/**
 */

void pint(void)
{
	printf("%d\n", first->n);
}
