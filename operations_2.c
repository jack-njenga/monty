#include "monty.h"
/**
 * add - adds up the top 2 elements
 * @line: line of the command
 */
void add(int line)
{
	stack_t *head = first, *next = NULL;
	int sum, len = len_stack();

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	sum = ((first->n) + ((first->next)->n));
	next->n = sum;
	first = next;
	free(head);
}
/**
 * mod - nothing else to do
 * @line: line of command
 */
void mod(int line)
{
	int rem;
	stack_t *temp = first;
	int len = len_stack();

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	rem = (temp->next->n) % (temp->n);
	temp->next->n = rem;
	temp->next->prev = NULL;
	first = temp->next;
	free(temp);
}
/**
 * sub - subtracts the top 2 elements
 * @line: line number
 */
void sub(int line)
{
	int diff, len;
	stack_t *temp = first;

	len = len_stack();
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	diff = (temp->next->n) - (temp->n);
	temp->next->n = diff;
	temp->next->prev = NULL;
	first = temp->next;
	free(temp);
}
/**
 * _div - divides the top 2 elements
 * @line: line of command
 */
void _div(int line)
{
	int m = 0;
	stack_t *temp = first;
	int len = len_stack();

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	m = (temp->next->n) / (temp->n);
	temp->next->n = m;
	temp->next->prev = NULL;
	first = temp->next;
	free(temp);
}
/**
 * mul - multiplies the top 2 elements
 * @line: line of the command
 */
void mul(int line)
{
	int ans = 0;
	stack_t *temp = first;
	int len = len_stack();

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line);
		exit(EXIT_FAILURE);
	}
	ans = (temp->n) * (temp->next->n);
	temp->next->n = ans;
	temp->next->prev = NULL;
	first = temp->next;
	free(temp);
}
