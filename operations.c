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

	new = malloc(sizeof(stack_t));
	if (!new)
		error_malloc();
	else
	{
		new->n = num;
		new->prev = NULL;
		new->next = NULL;
	}
	if (first == NULL)
		first = new;
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
 * pall - prints everything in stack
 *
 * Return: void
 */
void pall(void)
{
	stack_t *temp = first;

	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
 * pint - prints the top most element of the stack
 * @line: line number
 */

void pint(int line)
{
	if (first == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	while (first->next != NULL)
		first = first->next;
	printf("%d\n", first->n);
}
/**
 * pop - pops out the top most element
 * @line: line number
 */
void pop(int line)
{
	stack_t *temp;

	if (first == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if (first->prev == NULL)
	{
		free(first);
		first = NULL;
		exit(0);
	}
	temp = first->prev;
	temp->next = NULL;
	free(first);
	first = temp;
}
/**
 * swap - swaps the top 2 elements
 * @line: line of the commnad
 */
void swap(int line)
{
	stack_t *head = first, *next = NULL;
	int len = len_stack();

	printf("%d\n", len);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	next = head->prev;
	head->prev = next->prev;
	head->next = next;
	next->next = NULL;
	next->prev = head;
	first = next;
}
