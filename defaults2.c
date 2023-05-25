#include "main.h"
/**
 * error_malloc - error for malloc
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
