#include "monty.h"
/**
 */
void push(int num)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	new->next = NULL;

	if (first == NULL)
	{
		first = new;
	}
	else
	{
		while (first->next != NULL)
		{
			first = first->next;
		}
		first->next = new;
		new->prev = first;
		first = new;
	}
}

/**
 */
void pall()
{
	stack_t *temp;

	temp = first;
	if (temp == NULL)
	{
		fprintf(stderr, "stack underflow\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (temp->prev != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
