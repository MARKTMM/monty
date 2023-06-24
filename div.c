#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element.
 * @head: linked list's head address.
 * @line_number: line number from file.
 * Return: nothing
 */
void _div(stack_t **head, unsigned int line_number)
{
	int div = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		dprintf(
				STDERR_FILENO,
				"L%d: can't div, stack too short\n",
				line_number
		       );
		error = 1;
		return;
	}
	if ((*head)->n == 0)
	{
		dprintf(
				STDERR_FILENO,
				"L%d: division by zero\n",
				line_number
		       );
		error = 1;
		return;
	}


	div = (((*head)->next)->n) / ((*head)->n);
	_pop(head, line_number);
	(*head)->n = div;
}
