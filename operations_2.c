#include "monty.h"
/**
 * add - adds up the top 2 elements
 * @line: line of the command
 */
void add(int line)
{
	stack_t *head = first;
	int sum, len = len_stack();

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = (head->n) + ((head->prev)->n);
	(head->prev)->n = sum;
	pop(line);
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
	rem = ((temp->prev)->n % temp->n);
	(temp->prev)->n = rem;
	pop(line);
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
	diff = (((temp->prev)->n) - (temp->n));
	(temp->prev)->n = diff;
	pop(line);
}
/**
 * _div - divides the top 2 elements
 * @line: line of command
 */
void _div(int line)
{
	int ans = 0;
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
	ans = ((temp->prev)->n / temp->n);
	(temp->prev)->n = ans;
	pop(line);
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
	ans = (((temp->prev)->n) * (temp->n));
	(temp->prev)->n = ans;
	pop(line);
}
