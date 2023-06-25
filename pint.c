#include "monty.h"

/**
 * _pint - prints value at top of the stack
 * @head: memory allocation of linked list's head
 * @line_number: number line we are reading
 * Return: null
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(
				STDERR_FILENO,
				"L%d: can't pint, stack empty\n",
				line_number
		       );
		error = 1;
		return;
	}
	printf("%d\n", (*head)->n);
}
