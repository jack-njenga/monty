#ifndef MONTY_H
#define MONTY_H

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/* ... */
#define BUFFER_SIZE 1024
#define MAX_ARR 64
#define MIN_ARR 8

/* structures */
/**
 * struct stack_s - doubly linked list representation of
 * a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @filename: filename
 * @content: content
 * @commands: commands
 * @buff: buffer
 * @the_first: the first element in the stack
 *
 * Description: global variables
 */
typedef struct global_s
{
	const char *filename;
	char content[BUFFER_SIZE];
	char *commands[MAX_ARR];
	char *buff[MAX_ARR];
	stack_t *the_first;
} global_t;

/* prototypes */

/*files*/
void read_file(void);
void check_file(void);
void populate(char *token, int line);

/*commands*/
void command_checker(char **cmd, int line);

/*operations*/
void push(int num);
void pall(void);
void pint(int line);
void pop(int line);
void swap(int line);

/*operations_2*/
void add(int line);
void mod(int line);
void sub(int line);
void _div(int line);
void mul(int line);


/* stack_checks*/
int len_stack(void);

/*defaults */
void _default(void);
void error_file(void);
void error_read(void);
void error_push(int line);
void error_command(int line, char *str);
void error_malloc(void);

global_t global;
stack_t *first;

#endif
